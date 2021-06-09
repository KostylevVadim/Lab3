#include "pch.h"
#include "gtest/gtest.h"
#include "../Lab03/Set.h"
int MapChecks(int a) {
    return a * 3;
}
bool IsEvens(int a) {
    return a % 2 == 0;
}
int ReduceChecks(int a, int b) {
    return a + b;
}
TEST(SetTest, TestAdd) {
    Set<int> tree;
    tree.add(0);
    tree.add(1);
    tree.add(-1);
    EXPECT_EQ(tree.GetRoot()->num, 0);

    EXPECT_EQ(tree.GetRoot()->left->num, -1);

    EXPECT_EQ(tree.GetRoot()->right->num, 1);
}
TEST(SetTest, TestRemove) {
    Set<int> tree;
    tree.add(0);
    tree.add(1);
    tree.add(-1);
    tree.add(-2);
    tree.remove(-1);
    EXPECT_EQ(tree.GetRoot()->left->num, -2);
    tree.add(-1);
    tree.add(-3);
    tree.remove(-2);
    EXPECT_EQ(tree.GetRoot()->left->num, -1);
    tree.remove(0);
    EXPECT_EQ(tree.GetRoot()->num, 1);
}
TEST(SetTest, TestSearch) {
    Set<int> tree;
    for (int i = 0; i < 40; i++)
        tree.add(i);
    for (int i = 0; i < 40; i++) {
        EXPECT_TRUE(tree.find(i));
    }

}
TEST(SetTest, TestSubSet) {
    Set<int> x;
    x.add(0);
    x.add(2);
    x.add(1);
    x.add(3);
    x.add(-1);
    Set<int> y;
    y.add(2);
    y.add(1);
    y.add(3);
    y.add(4);
    EXPECT_FALSE(x.search_subset(y));
    Set<int> z;
    z.add(0);
    z.add(3);
    z.add(1);
    EXPECT_TRUE(x.search_subset(z));
}
TEST(SetTest, TestPlusMultMin) {
    Set<int> x;
    x.add(0);
    x.add(2);
    x.add(1);
    x.add(3);
    x.add(-1);
    Set<int> y;
    y.add(0);
    y.add(1);
    y.add(4);
    Set<int> s = x + y;
    Set<int> m = x * y;
    Set<int> min = x - y;
    EXPECT_EQ(s.GetRoot()->num, 0);
    EXPECT_EQ(s.GetRoot()->left->num, -1);
    EXPECT_EQ(s.GetRoot()->right->num, 2);
    EXPECT_EQ(s.GetRoot()->right->right->num, 3);
    EXPECT_EQ(m.GetRoot()->num,0);
    EXPECT_EQ(m.GetRoot()->right->num, 1);
    EXPECT_EQ(min.GetRoot()->right->num, 2);
    EXPECT_EQ(min.GetRoot()->num, -1);
    EXPECT_EQ(min.GetRoot()->right->right->num, 3);
}

TEST(SetTest,TestMapReduceWhere) {
    Set<int> x;
    x.add(0);
    x.add(2);
    x.add(1);
    x.add(3);
    x.add(-1);
    Set<int> y = x.Mapset(MapChecks);
    EXPECT_EQ(y.GetRoot()->left->num, -3);
    EXPECT_EQ(y.GetRoot()->right->num, 6);

    EXPECT_EQ(y.GetRoot()->right->left->num, 3);

    EXPECT_EQ(y.GetRoot()->right->right->num, 9);
    int z = x.Reduceset(ReduceChecks, 0);
    EXPECT_EQ(z, 15);
    Set<int> c = x.Whereset(IsEvens);
    EXPECT_EQ(x.GetRoot()->num, 0);
    EXPECT_EQ(x.GetRoot()->right->num, 6);
}
