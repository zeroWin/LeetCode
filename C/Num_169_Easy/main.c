/**
 * 169. Majority Element
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

 * You may assume that the array is non-empty and the majority element always exist in the array.
 **/
#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize);
int main()
{
    printf("Hello world!\n");
    return 0;

}

int majorityElement(int* nums, int numsSize) {
    int i,j,key;
    int major = numsSize/2;
    for(i = 1; i < numsSize; ++i) // 插入排序
    {
        key = nums[i];
        j = i-1;
        while(j >=0 && nums[j] > key)
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
    key = nums[0];
    j = 1;
    for(i = 1; i < numsSize; ++i) // 排序之后n/2处一定是major num，不用这么再找
    {
        if(nums[i] == key)
        {
            ++j;
            if(j > major)
                break;
        }
        else
        {
            key = nums[i];
            j = 1;
        }
    }
    return key;
}


int majorityElement(int* nums, int numsSize) {
    int i,j,key;
    int major = numsSize/2;
    for(i = 1; i < numsSize; ++i) // 插入排序
    {
        key = nums[i];
        j = i-1;
        while(j >=0 && nums[j] > key)
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
    return nums[major];
}
