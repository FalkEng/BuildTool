#include <BuildTool/action_graph.hpp>
#include <gtest/gtest.h>

TEST(ActionGraphTest, emptyJson)
{
    std::string current_dir = std::filesystem::current_path().string();
    char *data[] = {"build_file.cpp", "-t", "-b", ""};
    strcpy(data[3], current_dir.c_str()); // TODO fix error
    char **data_ptr = data;
    BuildParams params(data_ptr, data_ptr + 4);
    ActionGraph graph(params);
    // clang-format off
    const json json_data = R"(
    [
    ]
    )"_json;
    // clang-format on
    graph.loadFromJson(json_data);
    EXPECT_EQ(graph.numActions(), 0);
    EXPECT_EQ(graph.numDeps(), 0);
}

TEST(ActionGraphTest, parseJson)
{
    std::string current_dir = std::filesystem::current_path().string();
    char *data[] = {"build_file.cpp", "-t", "-b", ""};
    strcpy(data[3], current_dir.c_str());
    char **data_ptr = data;
    BuildParams params(data_ptr, data_ptr + 4);
    ActionGraph graph(params);
    // clang-format off
    const json json_data = R"(
    [
        {
            "type" : 0
            "in_file" : ["fileA", "fileB"]
            "out_file" : "fileC"
        },
        {
            "type" : 1
            "in_file" : ["fileD", "fileE"]
            "out_file" : "fileF"
        }
    ]
    )"_json;
    // clang-format on
    graph.loadFromJson(json_data);
    EXPECT_EQ(graph.numActions(), 2);
    EXPECT_EQ(graph.numDeps(), 4);
}

TEST(ActionGraphTest, testDepJson)
{
    std::string current_dir = std::filesystem::current_path().string();
    char *data[] = {"build_file.cpp", "-t", "-b", ""};
    strcpy(data[3], current_dir.c_str());
    char **data_ptr = data;
    BuildParams params(data_ptr, data_ptr + 4);
    ActionGraph graph(params);
    // clang-format off
    const json json_data = R"(
    [
        {
            "type" : 0
            "in_file" : ["fileA", "fileB"]
            "out_file" : "fileC"
        }
    ]
    )"_json;
    // clang-format on
    graph.loadFromJson(json_data);
    auto &depsRange = graph.getDeps(std::filesystem::path("fileA"));
    EXPECT_EQ(std::distance(depsRange.first, depsRange.second), 1);
    std::for_each(depsRange.first, depsRange.second, [](const Action *action) {

    })
}