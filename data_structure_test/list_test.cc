#include "data_structure/list.h"

#include "gtest/gtest.h"

// POD(Plain Old Data)
TEST(NodeUnitTest, ValueInitialOfPodNode) {
  Node<int> pod_node;

  ASSERT_TRUE(pod_node.value == 0);
  ASSERT_TRUE(pod_node.next == NULL);
}

TEST(NodeUnitTest, ValueInitialOfClassNode) {
  Node<std::string> class_node;

  ASSERT_TRUE(class_node.value == "");
  ASSERT_TRUE(class_node.next == NULL);
}

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from list_test.cc£¡\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}