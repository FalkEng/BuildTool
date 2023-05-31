#pragma once
#include <BuildTool/action.hpp>
#include <array>
#include <mutex>
#include <queue>
#include <vector>

class Scheduler
{
public:
  Scheduler(std::string build_dir);

  void addTask(const size_t id);

  void build();

  bool empty();

private:
  std::string build_dir_;
  std::priority_queue<size_t> tasks_;
  std::mutex prio_mutex_;
  void workerLoop();
};