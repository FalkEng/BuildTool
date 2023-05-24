#include <BuildTool/action.hpp>

std::string ActionData::getCompileCommand() {}

std::string ActionData::getLinkCommand() {}

std::string ActionData::getCmd() {
  switch (type_) {
  case ActionType::Compile:
    return getCompileCommand();
  case ActionType::Link:
    return getLinkCommand();
  }
}

void Action::execute() {}

void from_json(const json &j, Action &data) {
  j.at("out_file").get_to(data.data_.out_file_);
  j.at("in_files").get_to(data.data_.in_files_);
  j.at("type").get_to(data.data_.type_);
}

void to_json(json &j, const Action &data) {
  j = json{{"out_file", data.data_.out_file_},
           {"in_files", data.data_.in_files_},
           {"type", data.data_.type_}};
}
