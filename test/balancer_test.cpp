#include "../src/balancer/balancer.hpp"
#include <cstdint>
#include <gtest/gtest.h>

struct TestInstance {
  int fake_charge;
  int get_charge();
};

int TestInstance::get_charge() { return fake_charge; }

TEST(balancer_test, instance_insertion) {
  TestInstance i1 = {0};
  TestInstance i2 = {4};
  Balancer<TestInstance> B;
  int res = B.insert(&i1);
  ASSERT_EQ(res, 1);
  res = B.insert(&i2);
  ASSERT_EQ(res, 2);
  TestInstance *laziest;
  laziest = B.laziest();
  ASSERT_EQ(reinterpret_cast<int64_t>(laziest), reinterpret_cast<int64_t>(&i1));
}
