#include <BuildTool/artifact_parser.hpp>
#include <gtest/gtest.h>
#include <stdio.h>

using namespace nlohmann::literals;

TEST(IncStorageTest, ExampleJson) {
  IncludeStorage inc_stor;
  // clang-format off
  json data = R"(
  [
    {
        "name": "subA",
        "exe": false,
        "root": "subA",
        "srcs": [
            "src/ClassA.cpp",
            "src/main.cpp"
        ],
        "incs": [
            "inc"
        ]
    },
    {
        "name": "subB",
        "exe": false,
        "root": "subB",
        "srcs": [
            "src/main.cpp"
        ],
        "incs": [
            "inc"
        ],
        "deps": [
            "subA"
        ]
    }
  ]
  )"_json;
  // clang-format on

  inc_stor.addIncludes(data, "example/build.json");
  EXPECT_EQ(inc_stor.includes_["example/build.json/subA"],
            "-Iexample\\subA\\inc ");
  ASSERT_EQ(inc_stor.includes_["example/build.json/subB"],
            "-Iexample\\subB\\inc ");
}

TEST(ParserTest, EmptyFile) {
  ArtifactParser parser;
  json data = R"([])"_json;
  parser.parse(data, "");
}

TEST(ParserTest, MissingName) {
  ArtifactParser parser;
  // clang-format off
  json data = R"(
  [
    {
        "exe": false,
        "root": "subA",
        "srcs": [
            "src/ClassA.cpp",
            "src/main.cpp"
        ],
        "incs": [
            "inc"
        ]
    }
  ]
  )"_json;
  // clang-format on
  EXPECT_ANY_THROW(parser.parse(data, ""));
}

TEST(ParserTest, MissingExe) {
  ArtifactParser parser;
  // clang-format off
  json data = R"(
  [
    {
        "name": "subA",
        "root": "subA",
        "srcs": [
            "src/ClassA.cpp",
            "src/main.cpp"
        ],
        "incs": [
            "inc"
        ]
    } 
  ]
  )"_json;
  // clang-format on
  EXPECT_ANY_THROW(parser.parse(data, ""));
}
TEST(ParserTest, MissingRoot) {
  ArtifactParser parser;
  // clang-format off
  json data = R"(
  [
    {
        "name": "subA",
        "exe": false,
        "srcs": [
            "src/ClassA.cpp",
            "src/main.cpp"
        ],
        "incs": [
            "inc"
        ]
    } 
  ]
  )"_json;
  // clang-format on
  EXPECT_ANY_THROW(parser.parse(data, ""));
}

TEST(ParserTest, MissingDep) {
  ArtifactParser parser;
  // clang-format off
  json data = R"(
  [
    {
        "name": "subA",
        "exe": false,
        "root": "subA",
        "srcs": [
            "src/ClassA.cpp",
            "src/main.cpp"
        ],
        "incs": [
            "inc"
        ]
    },
    {
        "name": "subB",
        "exe": false,
        "root": "subB",
        "srcs": [
            "src/main.cpp"
        ],
        "incs": [
            "inc"
        ],
        "deps": [
            "./subC"
        ]
    }
  ]
  )"_json;
  // clang-format on
  EXPECT_ANY_THROW(parser.parse(data, "example/build.json"));
}