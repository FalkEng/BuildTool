#include <string>
#include <vector>

#define REGISTER_PLUGIN(a, b, )

class Action
{
public:
  Action(std::function<void(std::vector<string>, std::vector<string>)>, std::string out_file, std::vector<std::string> in_files);
  virtual void execute() const = 0;

private:
  std::vector<std::string> out_file_;

  std::vector<std::string> in_files_;
};
