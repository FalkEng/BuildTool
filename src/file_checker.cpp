#include <BuildTool/file_checker.hpp>
#include <algorithm>

bool ExistentChecker::checkDeprecated(const std::filesystem::path &file) const {
  return !std::filesystem::exists(file);
}

bool TimeStampChecker::checkDeprecated(const std::filesystem::path &file) {
  const std::filesystem::file_time_type &last_written =
      std::filesystem::last_write_time(file);
  bool updated{last_written != last_ts_};
  last_ts_ = last_written;
  return updated;
}

bool ContentChecker::checkDeprecated(const std::filesystem::path &file) const {
  return true;
}

bool FileChecker::checkDeprecated() {
  if (exist_check_.checkDeprecated(file_))
    return true;
  return ts_check_.checkDeprecated(file_) &&
         content_check_.checkDeprecated(file_);
}