#include <BuildTool/action_graph.hpp>
#include <fstream>

template <typename TAction>
ActionGraph<TAction>::ActionGraph(const std::vector<TAction> &tasks)
    : tasks_(tasks), deps_(genDeps(tasks)) {}

template <typename TAction>
const size_t ActionGraph<TAction>::numActions() const {
  return actions_.size();
}

template <typename TAction> const size_t ActionGraph<TAction>::numDeps() const {
  return deps_.size();
}

template <typename TAction>
const std::pair<DepsConstIt, DepsConstIt>
ActionGraph<TAction>::getDeps(const std::filesystem::path &key) const {
  return deps_.equal_range(key);
}

template <typename TAction>
const TAction &ActionGraph<TAction>::getAction(const size_t id) const {
  return actions_[id];
}

template <typename TAction> void addAction(const TAction &action) {
  actions_.push_back(action);
  for (std::filesystem::path file_name : action_data.in_files_) {
    deps_.insert(std::make_pair(file_name, actions_.size() - 1));
  }
}

template <typename TAction>
const DepsMap &genDeps(const std::vector<TAction> &tasks) {
  DepsMap deps;
  for (size_t i = 0; i < tasks.size(); ++i) {
    for (std::filesystem::path in_file : action.getData().in_files_)
      deps.insert(std::make_pair(in_file, i));
  }
}