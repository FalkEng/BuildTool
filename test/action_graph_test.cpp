#include <BuildTool/action_graph.hpp>
#include <BuildTool/action.hpp>
#include <gtest/gtest.h>

TEST(ActionGraphTest, emptyTasks)
{
  ActionGraph<Action> graph({});

  EXPECT_EQ(graph.numActions(), 0);
  EXPECT_EQ(graph.numDeps(), 0);
}

TEST(ActionGraphTest, parseJson)
{
  std::vector<Action> actions = {
      Action(ActionData{
          ActionType::Compile,
          std::filesystem::path("build_dir/fileC"),
          {std::filesystem::path("build_dir/fileA"),
           std::filesystem::path("build_dir/fileB")}})};
  ActionGraph graph(actions);

  EXPECT_EQ(graph.numActions(), 1);
  EXPECT_EQ(graph.numDeps(), 2);
}

TEST(ActionGraphTest, testDepJson)
{
  std::vector<Action> actions = {
      Action(ActionData{
          ActionType::Compile,
          std::filesystem::path("build_dir/fileC"),
          {std::filesystem::path("build_dir/fileA"),
           std::filesystem::path("build_dir/fileB")}})};
  ActionGraph graph(actions);

  auto depsRange = graph.getDeps(std::filesystem::path("build_dir/fileA"));
  EXPECT_EQ(std::distance(depsRange.first, depsRange.second), 1);
  for (auto &it = depsRange.first; it != depsRange.second; ++it)
  {
    const ActionData &data = graph.getAction(it->second).getData();
    EXPECT_EQ(data.out_file_, std::filesystem::path("build_dir/fileC"));
    EXPECT_EQ(data.type_, ActionType::Compile);
    EXPECT_EQ(data.in_files_[0], std::filesystem::path("build_dir/fileA"));
    EXPECT_EQ(data.in_files_[1], std::filesystem::path("build_dir/fileB"));
  };
}