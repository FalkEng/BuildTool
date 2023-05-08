#include <BuildTool/scheduler.hpp>
#include <functional>
#include <future>
#include <mutex>
#include <thread>

Scheduler::Scheduler(std::string build_dir) : build_dir_(build_dir) {}

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

void Scheduler::build() {
  std::vector<std::thread> threads;

  for (unsigned int i = 0; i < std::thread::hardware_concurrency(); i++) {
    threads.push_back(std::thread(std::bind(&Scheduler::workerLoop, this)));
  }
}