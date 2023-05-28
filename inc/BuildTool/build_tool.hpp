#include <BuildTool/action.hpp>
#include <BuildTool/action_graph.hpp>
#include <memory>

class BuildTool {
public:
  BuildTool(const BuildParams &params);
  void buildJson(std::filesystem::path json_to_build, bool test = false);
  void buildFile(std::filesystem::path file_to_build, bool test = false);
  void buildArtifact(std::string artifcat_name, bool test = false);
  void buildAll();
  const json &JsonFromFile(const std::filesystem::path &path);

  void build(std::vector<std::string> files);

  const std::vector<Action> &loadFromJson(const json &json_obj);

  const json &dumpToJson();

private:
  ActionGraph<Action> graph_;
};