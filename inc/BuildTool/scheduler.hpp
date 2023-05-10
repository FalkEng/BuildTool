#include <BuildTool/action.hpp>
#include <array>
#include <mutex>
#include <vector>

class Scheduler
{
public:
  Scheduler(std::string build_dir);

  void addTask(Action &task);

  void build();

  bool empty();

private:
  std::string build_dir_;
  std::vector<Action> tasks_;
  std::mutex prio_mutex_;
  void workerLoop();
};