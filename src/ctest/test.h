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
#define COLOR(a, b) "\033["#b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a,34)
#define YELLOW(a) COLOR(a, 33)

#define COLOR_HL(a, b) "\033[1;"#b "m" a "\033[0m"

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a,34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define TEST(a, b)\
void a##_ctest_##b();\
__attribute__((constructor))\
void add##_ctest_##a##_ctest_##b() {\
    add_function(a##_ctest_##b, #a "." #b);\
}\
void a##_ctest_##b()


#define TYPE_STR(a) _Generic((a),\
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    long long : "%lld",\
    char * : "%s"\
)

#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE_STR(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, comp) {\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    ctest_info.total += 1;\
    if (_a comp _b) ctest_info.success += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect " #a " " #comp " " #b " actual : "));\
        P(_a, YELLOW_HL);\
        P(" vs ", YELLOW_HL);\
        P(_b, YELLOW_HL);\
        printf("\n\n");\
    }\
    printf(GREEN("[-----------] ") #a" "#comp " "#b);\
    printf(" %s\n", (_a) comp (_b) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)

extern struct FunctionInfo ctest_info;

struct FunctionInfo{
    int total, success;
};


typedef void(*TestFuncT)();

typedef struct Function {
    TestFuncT func;
    const char *str;
}Function;

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#endif
