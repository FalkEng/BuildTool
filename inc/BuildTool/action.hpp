#include <nlohmann/json.hpp>
#include <vector>

enum class ActionType { Compile, Link, Depend };
using json = nlohmann::json;

struct ActionData {
  std::string getCompileCommand();

  std::string getLinkCommand();

  std::string getCmd();
  ActionType type_;
  std::string out_file_;
  std::vector<std::string> in_files_;
};

void from_json(const json &j, Action &data);
void to_json(json &j, const Action &data);

class Action {
public:
  Action(ActionData &data);
  ~Action() {}
  void execute();

  std::string cmd_;
  ActionData data_;
};
