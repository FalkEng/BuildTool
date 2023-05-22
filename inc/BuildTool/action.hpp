#include <BuildTool/definitions.hpp>
#include <vector>

enum class ActionType
{
  Compile,
  Link,
  Depend
};

class Action
{
public:
  Action(std::vector<std::string> in_files, std::string out_file);

  void execute();

  std::string getCompileCommand(std::string out_file, std::string in_file,
                                std::string add_args);

  std::string getLinkCommand(std::string out_file,
                             std::vector<std::string> in_files,
                             std::string add_args);

private:
  ActionType type_;
  std::string out_file_;
  std::vector<std::string> in_files_;
};
