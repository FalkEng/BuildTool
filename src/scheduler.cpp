#include <BuildTool/scheduler.hpp>
#include <functional>
#include <future>
#include <mutex>
#include <thread>

Scheduler::Scheduler(std::string build_dir) : build_dir_(build_dir) {}

void Scheduler::workerLoop() {
  while (true) {
    {
      std::lock_guard<std::mutex> guard(prio_mutex_);
      if (tasks_.empty())
        return;
      // Action task;
      // task.execute();
    }
  }
}

void Scheduler::addTask(const size_t id) { tasks_.push(id); }

void Scheduler::build() {
  std::vector<std::thread> threads;

  for (unsigned int i = 0; i < std::thread::hardware_concurrency(); i++) {
    threads.push_back(std::thread(std::bind(&Scheduler::workerLoop, this)));
  }
  for (auto &thread : threads)
    thread.join();
}

bool Scheduler::empty() {
  std::lock_guard<std::mutex> guard(prio_mutex_);
  return tasks_.empty();
}