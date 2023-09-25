/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Sep 2023 07:43:29 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

//C语言测试框架自定义头文件
//添加函数:后面使用两个宏Name(a, b), Str(Name(a, b));代替

#define TEST(a, b)\
void a##_ctest_##b();\
__attribute__((constructor))\
void add##_ctest_##a##_ctest_##b() {\
    add_function(a##_ctest_##b, #a "_ctest_" #b);\
}\
void a##_ctest_##b()

#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False");

typedef void(*TestFuncT)();

typedef struct Function {
    TestFuncT func;
    const char *str;
}Function;

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#endif
