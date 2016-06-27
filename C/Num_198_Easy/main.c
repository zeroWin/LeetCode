/**
 * 198. House Robber
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int rob(int* nums, int numsSize);

int main()
{
    int nums[7] = {4,1,2,7,5,3,1};
    int a = rob(nums,7);
    printf("Hello world!\n %d",a);
    return 0;
}


//// 递归复杂度太高了
//int rob(int* nums, int numsSize) {
//    int a = 0;
//    int b = 0;
//    if(numsSize < 1)
//        return 0;
//    // 不偷第一个房间
//    a += rob(nums+1,numsSize-1);
//    // 偷第一个房间
//    b += nums[0] + rob(nums + 2, numsSize - 2);
//    return a > b? a:b;
//}

// 采用动态规划
int rob(int* nums, int numsSize) {
    int i,j,l;
    int a,b;
    if(numsSize == 0)
        return 0;
    int **arrayResult = (int **)malloc(sizeof(int *) * numsSize);

    for(i = 0; i < numsSize; ++i)
    {
        arrayResult[i] = (int *)malloc(sizeof(int) * numsSize);
        memset(arrayResult[i],0,sizeof(int) * numsSize);
    }
    for(i = 0; i < numsSize; ++i)
        arrayResult[i][i] = nums[i];

    for(l = 2; l <= numsSize; ++l)
    {
        for(i = 0; i < numsSize - l + 1; ++i)
        {
            j = i + l - 1;
            a = arrayResult[i+1][j];
            if(i + 2 > j)
                b = arrayResult[i][i];
            else
                b = arrayResult[i][i] + arrayResult[i+2][j];
            if(a > b)
                arrayResult[i][j] = a;
            else
                arrayResult[i][j] = b;
        }
    }

    return arrayResult[0][numsSize-1];
}
