#include <BuildTool/build_tool.hpp>
#include <fstream>

BuildTool::BuildTool(const BuildParams &params)
    : graph_(loadFromJson(JsonFromFile(params.build_dir_))) {}
void BuildTool::buildJson(std::filesystem::path json_to_build, bool test)
{
  if (!exists(json_to_build))
    return;
}
void BuildTool::buildFile(std::filesystem::path file_to_build, bool test)
{
  if (file_to_build.extension() == ".json")
  {
    buildJson(file_to_build, test);
  }
  else
  {
  }
}
void BuildTool::buildArtifact(std::string artifcat_name, bool test) {}
void BuildTool::buildAll() {}

const std::vector<Action> &BuildTool::loadFromJson(const json &json_obj)
{
  for (json action_json : json_obj)
  {
    const ActionData &action_data = action_json.get<ActionData>();
  }
}

const json &BuildTool::dumpToJson() { return json{}; }

void createBuildDir(const std::filesystem::path &path)
{
  std::filesystem::create_directory(path);
}

const json &BuildTool::JsonFromFile(const std::filesystem::path &path)
{
  if (!std::filesystem::exists(path))
    createBuildDir(path);
  const std::filesystem::path &graph_dir = path / "graph.json";
  if (!std::filesystem::exists(graph_dir))
  {
    std::ofstream o(graph_dir.string());
    return json{};
  }
  std::ifstream f(graph_dir);
  return json::parse(f);
}