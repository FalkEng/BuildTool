#include <BuildTool/build_tool.hpp>

BuildTool::BuildTool(const BuildParams &params) : graph_() {}
void BuildTool::buildJson(std::filesystem::path json_to_build, bool test) {
  if (!exists(json_to_build))
    return;
}
void BuildTool::buildFile(std::filesystem::path file_to_build, bool test) {
  if (file_to_build.extension() == ".json") {
    buildJson(file_to_build, test);
  } else {
  }
}
void BuildTool::buildArtifact(std::string artifcat_name, bool test) {}
void BuildTool::buildAll() {}

const std::vector<Action> &BuildTool::loadFromJson(const json &json_obj) {
  for (json action_json : json_obj) {
    const ActionData &action_data = action_json.get<ActionData>();
  }
}

template <typename TAction> json BuildTool::dumpToJson() { return json{}; }

template <typename TAction>
void ActionGraph<TAction>::loadFromFile(const std::filesystem::path &path) {
  const std::filesystem::path &graph_dir = params_.build_dir_ / "graph.json";
  if (std::filesystem::exists(graph_dir)) {
    std::ifstream f(graph_dir);
    loadFromJson(json::parse(f));
  }
}