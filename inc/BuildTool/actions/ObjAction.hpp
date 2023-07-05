#pragma once
#include <BuildTool/file_checker.hpp>
#include <filesystem>
#include <variant>
#include <vector>

enum class BuildStatus { Deprecated, Built };

template <class PredT, class SuccT> class Obj {
public:
  Obj();
  bool checkDeprecated() const;
  virtual void update() const = 0;
  void propagateDeprecated();
  BuildStatus &getStatus();

private:
  FileChecker file_checker_;
  std::vector<PredT *> pred_;
  std::vector<SuccT *> succ_;
  std::filesystem::path file_;
  BuildStatus status_;
};