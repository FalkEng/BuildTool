#include <BuildTool/action_graph.hpp>
#include <fstream>

template <typename TAction>
ActionGraph<TAction>::ActionGraph(const std::vector<TAction> &actions)
    : actions_(actions), deps_(genDeps(actions)) {}

template <typename TAction>
const size_t ActionGraph<TAction>::numActions() const
{
  return actions_.size();
}

template <typename TAction>
const size_t ActionGraph<TAction>::numDeps() const
{
  return deps_.size();
}

template <typename TAction>
const std::pair<DepsConstIt, DepsConstIt>
ActionGraph<TAction>::getDeps(const std::filesystem::path &key) const
{
  return deps_.equal_range(key);
}

template <typename TAction>
const TAction &ActionGraph<TAction>::getAction(const size_t id) const
{
  return actions_[id];
}

template <typename TAction>
void ActionGraph<TAction>::addAction(const TAction &action)
{
  actions_.push_back(action);
  for (std::filesystem::path file_name : action_data.in_files_)
  {
    deps_.insert(std::make_pair(file_name, actions_.size() - 1));
  }
}

template <typename TAction>
const DepsMap ActionGraph<TAction>::genDeps(const std::vector<TAction> &actions)
{
  DepsMap deps;
  for (size_t i = 0; i < actions.size(); ++i)
  {
    for (std::filesystem::path in_file : actions[i].getData().in_files_)
      deps.insert(std::make_pair(in_file, i));
  }
  return deps;
}