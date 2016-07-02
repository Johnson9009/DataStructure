// Copyright (c) 2016 Johnson9009. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "data_structure/list.h"

#include "gtest/gtest.h"

// POD(Plain Old Data)
TEST(NodeUnitTest, ValueInitialOfPodNode) {
  Node<int> pod_node;

  ASSERT_EQ(pod_node.value, 0);
  ASSERT_EQ(pod_node.next, NULL);
}

TEST(NodeUnitTest, ValueInitialOfClassNode) {
  Node<std::string> class_node;

  ASSERT_EQ(class_node.value, "");
  ASSERT_EQ(class_node.next, NULL);
}

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from list_test.cc!\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
