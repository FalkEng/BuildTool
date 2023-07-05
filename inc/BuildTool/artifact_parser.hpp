#pragma once
#include <filesystem>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

using json = nlohmann::json;

struct IncludeStorage {
  void addIncludes(std::filesystem::path file_path);
  void addIncludes(json json_file, std::filesystem::path file_path);
  std::unordered_map<std::filesystem::path, std::string> includes_;
};

class ArtifactParser {
public:
  ArtifactParser();

  void parse(std::filesystem::path file_path);
  void parse(json json_file, std::filesystem::path file_path);
  void sanatize(json json_file);

private:
  IncludeStorage inc_stor_;
};