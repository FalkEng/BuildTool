#include <BuildTool/action.hpp>

Action::Action(std::vector<std::string> in_files, std::string out_file) {}

void Action::execute() {}

std::string Action::compile(std::string out_file, std::string in_file,
                            std::string add_args) {
  return "g++ -c" + in_file + " -o" + out_file + add_args;
}