#include <BuildTool/action.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

class ArtifactParser {
public:
  ArtifactParser();

  void parse(std::string file_path);

private:
  std::unordered_map<std::string, Action> actions_;
};