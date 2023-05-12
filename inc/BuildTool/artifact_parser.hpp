#include <BuildTool/action.hpp>
#include <string>
#include <filesystem>
#include <unordered_map>

struct IncludeStorage
{
  void addIncludes(std::filesystem::path file_path);

  std::unordered_map<std::filesystem::path, std::string> includes_;
};

class ArtifactParser
{
public:
  ArtifactParser();

  void parse(std::filesystem::path file_path);

private:
  std::unordered_map<std::string, Action> actions_;
  IncludeStorage inc_stor_;
};