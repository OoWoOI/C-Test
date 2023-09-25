/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Sep 2023 07:51:22 PM CST
 ************************************************************************/

#include<ctest/test.h>
#include<string.h>
#include<stdio.h>

int func_cnt = 0;
Function func_arr[100];

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        printf("Run Tests : %s\n", 
                func_arr[i].str);
        func_arr[i].func();
        printf("Run End\n");
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
     func_arr[func_cnt].func = func;
     func_arr[func_cnt].str = strdup(str);
     func_cnt++;
    return ;
}
