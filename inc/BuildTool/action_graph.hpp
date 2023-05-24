#include <BuildTool/action.hpp>
#include <BuildTool/build_params.hpp>
#include <filesystem>
#include <unordered_map>

class ActionGraph {
public:
  ActionGraph(const BuildParams &params);

  void addAction();

  const Action &getAction(const std::string key);

  void parseFromJson(const std::filesystem::path &json_path);

  void dumpToJson(const std::filesystem::path &json_path);

private:
  std::vector<Action> actions_;
  std::unordered_map<std::string, Action *> deps_;
  const BuildParams params_;
};