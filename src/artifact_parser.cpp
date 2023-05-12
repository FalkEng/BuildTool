#include <BuildTool/artifact_parser.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void IncludeStorage::addIncludes(std::filesystem::path file_path)
{
    std::ifstream f(file_path);
    json data = json::parse(f);
    std::filesystem::path base_path = file_path.parent_path();
    for (const auto &artifact : data)
    {
        std::string root = artifact["root"];
        std::stringstream ss;
        for (const auto &inc : artifact["incs"])
            ss << "-I" << base_path / root / inc << " ";
        includes_.insert(std::make_pair(file_path / artifact["name"], ss.str()));
    }
}

ArtifactParser::ArtifactParser()
{
}

void ArtifactParser::parse(std::filesystem::path file_path)
{
    std::ifstream f(file_path);
    json data = json::parse(f);
    // get an iterator to the first element

    std::unordered_map<std::string, std::string> includes;
    std::string key;
    std::set<std::filesystem::path> file_set_;
    // serialize the element that the iterator points to
    for (const auto &item : data)
    {
        for (const auto &dep_json : item["deps"])
        {
            std::string dep_str = to_string(dep_json);
            size_t pos = dep_str.find_last_of("\\/");
            std::filesystem::path dep_file = file_path / dep_str.substr(0, pos);
            if (file_set_.find(dep_file) != file_set_.end())
            {
                inc_stor_.addIncludes(dep_file);
            }
            std::string artifact_name = dep_str.substr(pos + 1);
        }
    }
}
