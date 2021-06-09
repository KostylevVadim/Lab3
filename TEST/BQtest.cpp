#include "pch.h"
#include "gtest/gtest.h"
#include "../Lab03/BQ.h"

int MapCheckb(int a) {
    return a * 3;
}
bool IsEvenb(int a) {
    return a % 2 == 0;
}
int ReduceCheckb(int a, int b) {
    return a + b;
}

TEST(BQTest, TestAdd) {
    BQ<int> tree = BQ<int>();
    tree.add(1000, 5);
    tree.add(1, 10);
    tree.add(100, 2);
    EXPECT_EQ(tree.GetRoot()->num, 1000);
    EXPECT_EQ(tree.GetRoot()->left->num,100);
    EXPECT_EQ(tree.GetRoot()->right->num, 1);
}
TEST(BQTest, TestRemove) {
    BQ<int> tree = BQ<int>();
    tree.add(0, 10);
    tree.add(100, 5);
    tree.add(-1, 6);
    tree.add(1000, 4);
    tree.add(-100, 50);
    EXPECT_EQ(tree.GetRoot()->num, 0);
    EXPECT_EQ(tree.GetRoot()->left->num, 100);
    EXPECT_EQ(tree.GetRoot()->left->right->num, -1);
    EXPECT_EQ(tree.GetRoot()->left->left->num, 1000);
    EXPECT_EQ(tree.GetRoot()->right->num, -100);
    tree.remove(0);
    EXPECT_EQ(tree.GetRoot()->num, 100);
}
TEST(BQTest, TestSearch) {
    BQ<int> tree = BQ<int>();
    tree.add(0, 10);
    tree.add(100, 5);
    tree.add(-1, 6);
    tree.add(1000, 4);
    tree.add(-100, 50);
    EXPECT_TRUE(tree.find(0));
    EXPECT_TRUE(tree.find(100));
    EXPECT_TRUE(tree.find(-1));
    EXPECT_TRUE(tree.find(1000));

    EXPECT_FALSE(tree.find(100000));
    EXPECT_FALSE(tree.find(6));
    EXPECT_FALSE(tree.find(10));
    EXPECT_FALSE(tree.find(5));
    EXPECT_FALSE(tree.find(50));
}
TEST(BQTest, TestSubfromto) {
    BQ<int> tree = BQ<int>();
    tree.add(0, 10);
    tree.add(100, 5);
    tree.add(-1, 6);
    tree.add(1000, 4);
    tree.add(-100, 50);
    BQ<int>* dat = tree.SubQfromto(5,6);
    EXPECT_TRUE(dat->find(100));
    EXPECT_TRUE(dat->find(-1));
    EXPECT_FALSE(dat->find(-100));
    EXPECT_FALSE(dat->find(1000));
    
}
TEST(BQTest, TestMapReduceWhere) {
    BQ<int> tree = BQ<int>();
    tree.add(0, 10);
    tree.add(100, 5);
    tree.add(-1, 6);
    tree.add(1000, 4);
    tree.add(-100, 50);
    BQ<int> dat = tree.Map(MapCheckb);
    EXPECT_TRUE(dat.find(300)); 
    EXPECT_TRUE(dat.find(-3));
    EXPECT_TRUE(dat.find(3000));
    EXPECT_TRUE(dat.find(300));
    EXPECT_TRUE(dat.find(-300));
    int a = dat.Reduce(ReduceCheckb,0);
    EXPECT_TRUE(a==2997);
    BQ<int> n;
    n.add(0, 10);
    n.add(100, 5);
    n.add(-1, 6);
    n.add(1000, 4);
    n.add(-100, 50);
    
}