#include <BuildTool/action.hpp>
#include <array>
#include <mutex>
#include <queue>

class Scheduler {
public:
  Scheduler();

private:
  std::priority_queue<const Action *> tasks_;
  std::mutex prio_mutex_;
  void workerLoop();
};