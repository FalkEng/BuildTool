#include <BuildTool/build_params.hpp>
#include <iterator>
#include <stdint.h>
#include <unordered_map>

using DepsMap = std::unordered_multimap<std::filesystem::path, size_t>;
using DepsConstIt = DepsMap::const_iterator;

template <typename TAction> class ActionGraph {
public:
  ActionGraph(const std::vector<TAction> &tasks);

  const std::pair<DepsConstIt, DepsConstIt>
  getDeps(const std::filesystem::path &key) const;

  const TAction &getAction(const size_t id) const;

  void addAction(const TAction &action);

  const size_t numActions() const;

  const size_t numDeps() const;

private:
  const std::vector<TAction> actions_;
  const DepsMap deps_;

  static const DepsMap &genDeps(const std::vector<TAction> &tasks);
};