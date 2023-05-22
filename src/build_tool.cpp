#include <BuildTool/build_tool.hpp>

BuildTool::BuildTool()
{
}
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
void BuildTool::buildArtifact(std::string artifcat_name, bool test)
{
}
void BuildTool::buildAll()
{
}
