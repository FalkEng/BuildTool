#include <BuildTool/action.hpp>
#include <BuildTool/build_params.hpp>
#include <unordered_map>
#include <iterator>

using DepsMap = std::unordered_multimap<std::filesystem::path, Action *>;
using DepsConstIt = DepsMap::const_iterator;
class ActionGraph
{
public:
  ActionGraph(const BuildParams &params);

  void loadFromFile(const std::filesystem::path &path);

  std::pair<DepsConstIt, DepsConstIt> getDeps(const std::filesystem::path &key) const;

  const size_t numActions() const;

  const size_t numDeps() const;

  void loadFromJson(const json &json_obj);

  json dumpToJson();

private:
  std::vector<Action> actions_;
  DepsMap deps_;
  const BuildParams params_;
};