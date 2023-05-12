#include <BuildTool/artifact_parser.hpp>
#include <gtest/gtest.h>
#include <stdio.h>

TEST(ParserTest, EmptyFile)
{
    ArtifactParser parser;
    parser.parse("C:\\Users\\admin\\Documents\\BuildTool\\test\\example\\build.json");
}

TEST(IncStorageTest, EmptyFile)
{
    IncludeStorage inc_stor;
    inc_stor.addIncludes("C:\\Users\\admin\\Documents\\BuildTool\\test\\example\\build.json");
    EXPECT_EQ(inc_stor.includes_["C:\\Users\\admin\\Documents\\BuildTool\\test\\example\\build.json\\subA"], "-I\"C:\\Users\\admin\\Documents\\BuildTool\\test\\example\\subA\\inc\" ");
}