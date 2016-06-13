/**
 * 217. Contains Duplicate
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize);
int main()
{
    printf("Hello world!\n");
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    int i,j,key;
    for(i = 1;i < numsSize; ++i)
    {
        j = i-1;
        key = nums[i];
        while(j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
    for(i = 1; i < numsSize; ++i)
        if(nums[i] == nums[i - 1])
            return true;
    return false;
}
