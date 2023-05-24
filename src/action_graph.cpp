#include <BuildTool/action_graph.hpp>
#include <fstream>

ActionGraph::ActionGraph(const BuildParams &params) : params_(params) {
  if (!std::filesystem::exists(params_.build_dir_))
    throw std::invalid_argument("build directory not found!");
  const std::filesystem::path &graph_dir = params_.build_dir_ / "graph.json";
  if (std::filesystem::exists(graph_dir)) {
    parseFromJson(graph_dir);
  }
}

void ActionGraph::parseFromJson(const std::filesystem::path &json_path) {
  std::ifstream f(json_path);
  nlohmann::json json_file = nlohmann::json::parse(f);
  for (nlohmann::json action_json : json_file) {
    Action action = action_json.get<Action>();
    actions_.push_back(action);
    for (std::string file_name : action.data_.in_files_) {
      deps_.insert(std::make_pair(file_name, &action));
    }
  }
}

void ActionGraph::dumpToJson(const std::filesystem::path &json_path) {}