#include <BuildTool/action.hpp>
#include <unordered_map>

class ActionGraph
{
public:
  ActionGraph();

  void addAction();

  const Action &getAction(const std::string key);

private:
  std::unordered_map<std::string, Action> actions_;
  std::filesystem::path build_dir;
};