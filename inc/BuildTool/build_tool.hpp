#include <filesystem>
#include <BuildTool/action_graph.hpp>

class BuildTool
{
public:
    BuildTool(std::filesystem::path build_dir);
    void buildJson(std::filesystem::path json_to_build, bool test = false);
    void buildFile(std::filesystem::path file_to_build, bool test = false);
    void buildArtifact(std::string artifcat_name, bool test = false);
    void buildAll();

    void build(std::vector<std::string> files);

private:
    ActionGraph graph_;
};