#include "../src/utils/priority.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include <vector>

struct TestInstance {
  std::vector<int> v;
  explicit TestInstance(std::vector<int> vector) { v = vector; }
  int key() { return v.size(); }
};

TEST(utils_tester, min_heap) {
  std::vector<int> v1{5, 5, 5};
  TestInstance instance1 = TestInstance(v1);
  std::vector<int> v2{5, 5, 5, 7, 7};
  TestInstance instance2 = TestInstance(v2);
  MinHeap<TestInstance> heap;
  heap.push(&instance1);
  heap.push(&instance2);
  TestInstance *top = heap.top();
  ASSERT_EQ(reinterpret_cast<int64_t>(top),
            reinterpret_cast<int64_t>(&instance1));
  instance2.v.resize(2);
  heap.update(&instance2);
  top = heap.top();
  ASSERT_EQ(reinterpret_cast<int64_t>(top),
            reinterpret_cast<int64_t>(&instance2));
}
