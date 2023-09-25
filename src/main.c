/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Sep 2023 07:39:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include<ctest/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(testFunc, add) {
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_EQ(add(5, 3), 9);
    EXPECT_EQ(add(6, 3), 9);
}

TEST(testFunc, add2) {
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_EQ(add(5, 4), 8);
    EXPECT_EQ(add(5, 4), 9);
}

TEST(test, Funcadd) {
    EXPECT_EQ(add(5, 5), 8);
    EXPECT_EQ(add(5, 5), 10);
    EXPECT_EQ(add(5, 5), 7); 
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
