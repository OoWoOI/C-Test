/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Sep 2023 07:51:22 PM CST
 ************************************************************************/

#include<ctest/test.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

int func_cnt = 0;
Function func_arr[100];
struct FunctionInfo ctest_info;

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        printf(GREEN("[====RUN====]") RED_HL(" %s\n"), func_arr[i].str);
        ctest_info.total = 0;
        ctest_info.success = 0; 
        func_arr[i].func();
        double rate = 1.0 * ctest_info.success / ctest_info.total;
        printf(GREEN("[  "));

        fabs(rate - 1.0) < 1e-6 ? printf(BLUE_HL("%6.2lf%%"), rate * 100) : printf(RED_HL("%6.2lf%%"), rate * 100.0);
        
        printf(GREEN("  ]") " total: %d success: %d\n", ctest_info.total, ctest_info.success);
        
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
     func_arr[func_cnt].func = func;
     func_arr[func_cnt].str = strdup(str);
     func_cnt++;
    return ;
}
