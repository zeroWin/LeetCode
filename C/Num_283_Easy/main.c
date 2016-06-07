/**
 * 283. Move Zeroes
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 **/
#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize);
int main()
{
    int nums[5] = {0,1,0,3,12};
    moveZeroes(nums,5);

    return 0;
}

/**
 * 有O(n)的方法，下次做到好好想想
 **/
void moveZeroes(int* nums, int numsSize) {
    int i,j;
    for(i = 0; i < numsSize - 1; ++i)
    {
        if(nums[i] != 0)
            continue;
        for(j = i + 1;j < numsSize; ++j)
        {
            if(nums[j] == 0)
                continue;
            nums[i] = nums[j];
            nums[j] = 0;
            break;
        }
        if(j == numsSize)
            break;
    }
}
