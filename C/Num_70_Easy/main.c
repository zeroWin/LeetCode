/**
 * 70. Climbing Stairs
 * You are climbing a stair case. It takes n steps to reach to the top.

 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 **/
#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n);

int main()
{
    printf("Hello world!\n");

    return 0;
}

//// 递归太慢了
//int climbStairs(int n) {
//    if(n < 0)
//        return 0;
//    if(n == 0)
//        return 1;
//    else
//        return climbStairs(n-1) + climbStairs(n-2);
//}

// 改成迭代
int climbStairs(int n) {
    int i = 1;
    int FN = 1;
    int FN_1 = 0;
    int temp;
    while(i <= n)
    {
        temp = FN;
        FN += FN_1;
        FN_1 = temp;
        i++;
    }
    return FN;
}
