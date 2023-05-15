#include <BuildTool/action.hpp>
#include <map>

class ActionGraph {
  ActionGraph();

  addAction();

  const Action &getAction(const std::string key);

private:
  std::unordered_map<std::string, Action> actions_;
};