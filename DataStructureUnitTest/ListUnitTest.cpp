#include "../DataStructure/List.h"
#include "gtest/gtest.h"

TEST(ListUnitTest, CreateNode)
{
	Node<int> *a = new Node<int>();
	ASSERT_TRUE(a != NULL);

}

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from ListUnitTest.cpp£¡\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}