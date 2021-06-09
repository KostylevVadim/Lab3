#include "pch.h"
#include "gtest/gtest.h"
#include "../Lab03/Btee.h"

int MapCheck(int a) {
    return a * 3;
}
bool IsEven(int a) {
    return a % 2 == 0;
}
int ReduceCheck(int a, int b) {
    return a + b;
}
TEST(TreeTest, TestAdd) {
    BTree<int> tree = BTree<int>();
    tree.add(0);
    tree.add(1);
    tree.add(-1);
    EXPECT_EQ(tree.GetRoot()->num,0);

    EXPECT_EQ(tree.GetRoot()->left->num, -1);

    EXPECT_EQ(tree.GetRoot()->right->num, 1);
}
TEST(TreeTest, TestRemove) {
    BTree<int> tree = BTree<int>();
    tree.add(0);
    tree.add(1);
    tree.add(-1);
    tree.add(-2);
    tree.remove(-1);
    EXPECT_EQ(tree.GetRoot()->left->num,-2);
    tree.add(-1);
    tree.add(-3);
    tree.remove(-2);
    EXPECT_EQ(tree.GetRoot()->left->num, -1);
    tree.remove(0);
    EXPECT_EQ(tree.GetRoot()->num,1);
}
TEST(TreeTest,TestSearch) {
    BTree<int> tree = BTree<int>();
    for (int i = 0; i < 40; i++)
        tree.add(i);
    for (int i = 0; i < 40; i++) {
        EXPECT_TRUE(tree.find(i));
    }

}
TEST(TreeTest, TestSubtree) {
    BTree<int> x;
    x.add(0);
    x.add(2);
    x.add(1);
    x.add(3);
    x.add(-1);
    BTree<int> y;
    y.add(2);
    y.add(1);
    y.add(3);
    EXPECT_TRUE(x.search_Subtree(y));
    y.add(4);
    EXPECT_FALSE(x.search_Subtree(y));
}
TEST(TreeTest, TestSubTreeValue) {
    
    BTree<int> x;
    x.add(0);
    x.add(2);
    x.add(1);
    x.add(3);
    x.add(-1);
}
TEST(TreeTest, TestMapReduceWhere) {
    BTree<int> x;
    x.add(0);
    x.add(2);
    x.add(1);
    x.add(3);
    x.add(-1);
    BTree<int> y=x.Map(MapCheck);
    EXPECT_EQ(y.GetRoot()->left->num,-3);
    EXPECT_EQ(y.GetRoot()->right->num,6);

    EXPECT_EQ(y.GetRoot()->right->left->num, 3);

    EXPECT_EQ(y.GetRoot()->right->right->num, 9);
    int z = x.Reduce(ReduceCheck, 0);
    EXPECT_EQ(z, 15);
    BTree<int>* w = x.Where(IsEven);
    EXPECT_EQ(w->GetRoot()->num, 0);
    EXPECT_EQ(w->GetRoot()->right->num, 6);
}