#include <BuildTool/action.hpp>
#include <array>
#include <mutex>
#include <queue>

class Scheduler {
public:
  Scheduler(std::string build_dir);

private:
  std::string build_dir_;
  std::priority_queue<const Action *> tasks_;
  std::mutex prio_mutex_;
  void workerLoop();
  void build();
};