#include <BuildTool/artifact_parser.hpp>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>

void IncludeStorage::addIncludes(std::filesystem::path file_path) {
  std::ifstream f(file_path);
  json data = json::parse(f);
  addIncludes(data, file_path);
}

void IncludeStorage::addIncludes(json json_file,
                                 std::filesystem::path file_path) {
  std::filesystem::path base_path = file_path.parent_path();
  for (const auto &artifact : json_file) {
    std::string root = artifact["root"];
    std::stringstream ss;
    for (const auto &inc : artifact["incs"])
      ss << "-I" << (base_path / root / inc).string() << " ";
    includes_.insert(std::make_pair(file_path / artifact["name"], ss.str()));
  }
}

ArtifactParser::ArtifactParser() {}

void ArtifactParser::parse(std::filesystem::path file_path) {
  std::ifstream f(file_path);
  json json_file = json::parse(f);
  parse(json_file, file_path);
}

void ArtifactParser::parse(json json_file, std::filesystem::path file_path) {
  // get an iterator to the first element

  std::unordered_map<std::string, std::string> includes;
  std::string key;
  std::set<std::filesystem::path> file_set_;
  // serialize the element that the iterator points to
  for (const auto &item : json_file) {
    sanatize(item);
    for (const auto &dep_json : item["deps"]) {
      std::string dep_str = to_string(dep_json);
      size_t pos = dep_str.find_last_of("\\/");
      std::filesystem::path dep_file =
          (file_path / dep_str.substr(0, pos)).lexically_normal();
      if (file_set_.find(dep_file) != file_set_.end()) {
        inc_stor_.addIncludes(dep_file);
      }
      std::string artifact_name = dep_str.substr(pos + 1);
      std::filesystem::path artifact_path = dep_file / artifact_name;

      auto it = inc_stor_.includes_.find(artifact_name);
      if (it == inc_stor_.includes_.end())
        throw std::invalid_argument("No artifact with name " + artifact_name +
                                    " found.");
    }
  }
}

void ArtifactParser::sanatize(json json_file) {
  if (json_file["name"].is_null()) {
    throw std::invalid_argument("No name argument found for artifact");
  }
  if (json_file["exe"].is_null()) {
    throw std::invalid_argument("No exe argument found for artifact");
  }
  if (json_file["root"].is_null()) {
    throw std::invalid_argument("No root argument found for artifact");
  }
}
