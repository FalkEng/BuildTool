#include <BuildTool/scheduler.hpp>
#include <mutex>

Scheduler::Scheduler() {}

void Scheduler::workerLoop() {
  const Action *task_ptr = nullptr;
  while (true) {
    std::lock_guard<std::mutex> guard(prio_mutex_);
    if (tasks_.empty())
      return;
    const Action *task_ptr = tasks_.top();
    tasks_.pop();
  }
  task_ptr->execute();
}