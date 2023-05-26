#include <BuildTool/build_params.hpp>
#include <gtest/gtest.h>

TEST(BuildParamsTest, withoutParams)
{
  char *data[] = {"build_file.cpp"};
  char **data_ptr = data;
  BuildParams params(data_ptr, data_ptr + 1);
  EXPECT_EQ(params.build_dir_, std::filesystem::path());
  EXPECT_EQ(params.test_, false);
  EXPECT_EQ(params.target_, "build_file.cpp");
}

TEST(BuildParamsTest, exampleParams)
{
  char *data[] = {"build_file.cpp", "-t", "-b", "build_dir"};
  char **data_ptr = data;
  BuildParams params(data_ptr, data_ptr + 4);
  EXPECT_EQ(params.build_dir_, std::filesystem::path("build_dir"));
  EXPECT_EQ(params.test_, true);
  EXPECT_EQ(params.target_, "build_file.cpp");
}

TEST(BuildParamsTest, missingParams)
{
  char *data[] = {"build_file.cpp", "-t", "-b"};
  char **data_ptr = data;
  EXPECT_ANY_THROW(BuildParams params(data_ptr, data_ptr + 3));
}