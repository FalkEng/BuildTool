#include <BuildTool/build_tool.hpp>

BuildTool::BuildTool(const BuildParams &params)
    : graph_(loadFromJson(JsonFromFile(params.build_dir_))) {}
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

const json &BuildTool::dumpToJson() { return json{}; }

const json &BuildTool::loadFromFile(const std::filesystem::path &path) {
  const std::filesystem::path &graph_dir = path / "graph.json";
  if (!std::filesystem::exists(graph_dir)) {
    throw std::invalid_argument("Argument parsing failed for argument " +
                                **std::prev(begin));
  }
  std::ifstream f(graph_dir);
  return json::parse(f);
}