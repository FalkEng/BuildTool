#include <BuildTool/build_tool.hpp>

using namespace std::filesystem;

enum class Command {
  SingleFile,
  AllChanges,

};

void printMan() {}

int main(int argc, char **argv) {
  if (argc == 0)
    printMan();
  BuildParams params(argv + 1, argv + argc);
  BuildTool tool(params);
  if (argv[1] == "build") {
    if (argc > 1) {
      path arg_path(argv[2]);
      if (arg_path.has_extension()) {
        tool.buildFile(arg_path);
        //
      } else {
        tool.buildArtifact(argv[2]);
      }
    } else {
      path json_path = current_path() / "build.json";
      tool.buildJson(json_path);
    }
  } else if (argv[1] == "test") { //
  } else
    printMan();
}