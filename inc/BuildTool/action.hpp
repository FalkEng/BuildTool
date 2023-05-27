#include <nlohmann/json.hpp>
#include <vector>

enum class ActionType { Compile, Link, Depend };
enum class BuildStatus { Deprecated, Built };
using json = nlohmann::json;

struct ActionData {
  std::string getCompileCommand() const;

  std::string getLinkCommand() const;

  std::string getCmd() const;
  ActionType type_;
  std::filesystem::path out_file_;
  std::vector<std::filesystem::path> in_files_;
};

class Action {
public:
  Action(const ActionData &data);
  ~Action() {}
  void execute();

  void setStatus(BuildStatus status);
  const ActionData &getData() const;

private:
  BuildStatus status_;
  const std::string cmd_;
  const ActionData data_;
};

void from_json(const json &j, ActionData &data);
void to_json(json &j, const ActionData &data);