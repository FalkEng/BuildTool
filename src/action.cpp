#include <BuildTool/action.hpp>

std::string ActionData::getCompileCommand() const { return ""; }

std::string ActionData::getLinkCommand() const { return ""; }

std::string ActionData::getCmd() const {
  switch (type_) {
  case ActionType::Compile:
    return getCompileCommand();
  case ActionType::Link:
    return getLinkCommand();
  }
}

Action::Action(const ActionData &data) : data_(data), cmd_(data.getCmd()) {}

void Action::execute() {}

const ActionData &Action::getData() const { return data_; }

void from_json(const json &j, ActionData &data) {
  j.at("out_file").get_to(data.out_file_);
  j.at("in_files").get_to(data.in_files_);
  j.at("type").get_to(data.type_);
}

void to_json(json &j, const ActionData &data) {
  j = json{{"out_file", data.out_file_},
           {"in_files", data.in_files_},
           {"type", data.type_}};
}
