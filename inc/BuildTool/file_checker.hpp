#include <filesystem>

class ExistentChecker {
public:
  bool checkDeprecated(const std::filesystem::path &file) const;
};

class TimeStampChecker {
public:
  bool checkDeprecated(const std::filesystem::path &file);

private:
  std::filesystem::file_time_type last_ts_;
};

class ContentChecker {
public:
  bool checkDeprecated(const std::filesystem::path &file) const;
};

class FileChecker {
public:
  FileChecker(const std::filesystem::path &file);
  bool checkDeprecated();

private:
  const std::filesystem::path file_;
  ExistentChecker exist_check_;
  TimeStampChecker ts_check_;
  ContentChecker content_check_;
};