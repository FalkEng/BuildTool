#include <BuildTool/scheduler.hpp>
#include <gtest/gtest.h>

TEST(SchedulerTest, EmptyQueue) {
  Scheduler scheduler("build/test");
  scheduler.build();
  ASSERT_TRUE(scheduler.empty()) << "Scheduler is not empty";
}

TEST(SchedulerTest, OneItemQueue) {
  Scheduler scheduler("build/test");
  Action action1{{}, ""};
  scheduler.addTask(action1);
  EXPECT_FALSE(scheduler.empty()) << "Action not added";
  scheduler.build();
  ASSERT_TRUE(scheduler.empty()) << "Scheduler is not empty";
}