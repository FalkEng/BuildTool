#include <string>
#include <vector>

class Action {
public:
  Action();

  void execute();

private:
  std::vector<std::string> out_file_;

  std::vector<std::string> in_files_;
};
