#include <BuildTool/action_graph.hpp>
#include <fstream>

ActionGraph::ActionGraph(const BuildParams &params) : params_(params)
{
  if (!std::filesystem::exists(params_.build_dir_))
    throw std::invalid_argument("build directory not found!");
}

void ActionGraph::loadFromFile(const std::filesystem::path &path)
{
  const std::filesystem::path &graph_dir = params_.build_dir_ / "graph.json";
  if (std::filesystem::exists(graph_dir))
  {
    std::ifstream f(graph_dir);
    loadFromJson(json::parse(f));
  }
}

void ActionGraph::loadFromJson(const json &json_obj)
{
  for (json action_json : json_obj)
  {
    const ActionData &action_data = action_json.get<ActionData>();
    Action &action = Action(action_data);
    actions_.push_back(action);
    for (std::filesystem::path file_name : action_data.in_files_)
    {
      deps_.insert(std::make_pair(file_name, &action));
    }
  }
}

json ActionGraph::dumpToJson()
{
  return json{};
}

const size_t ActionGraph::numActions() const
{
  return actions_.size();
}

const size_t ActionGraph::numDeps() const
{
  return deps_.size();
}

std::pair<DepsConstIt, DepsConstIt> ActionGraph::getDeps(const std::filesystem::path &key) const
{
  return deps_.equal_range(key);
}