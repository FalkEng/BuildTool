#include <string>
#include <vector>

class Action {
public:
  Action();
  void execute() const;

private:
  std::string out_file_;

  std::vector<std::string> in_file_;
  unsigned int level = 0;
};
