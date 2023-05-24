#include <filesystem>

struct BuildParams {

  BuildParams(char **begin, char **end);
  std::filesystem::path build_dir_{};
  bool test_{false};
  std::string target_{};
};