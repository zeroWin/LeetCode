/**
 * 350. Intersection of Two Arrays II
 * Given two arrays, write a function to compute their intersection.

 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 **/

#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int main()
{
    int num1[] = {61,24,20,58};
    int num2[] = {5,25,4,39,57};
    int num;
    intersect(num1,4,num2,5,&num);
    printf("Hello world!\n");
    return 0;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *arrayMax;
    int *arrayMin;
    int numMax;
    int numMin;
    int i,j,key;
    int *returnArray;
    *returnSize = 0;
    if(nums1Size == 0 || nums2Size == 0)
       return NULL;
    if(nums1Size > nums2Size)
    {
        arrayMax = nums1;
        arrayMin = nums2;
        numMax = nums1Size;
        numMin = nums2Size;
    }
    else
    {
        arrayMax = nums2;
        arrayMin = nums1;
        numMax = nums2Size;
        numMin = nums1Size;
    }
    returnArray = (int *)malloc(sizeof(int) * numMin);
    // sort arrayMax and arrayMin
    for(i = 1; i < numMin; ++i)
    {
        key = arrayMin[i];
        j = i - 1;
        while(j >= 0 && arrayMin[j] > key)
        {
            arrayMin[j + 1] = arrayMin[j];
            j = j - 1;
        }
        arrayMin[j + 1] = key;
    }

    for(i = 1; i < numMax; ++i)
    {
        key = arrayMax[i];
        j = i - 1;
        while(j >= 0 && arrayMax[j] > key)
        {
            arrayMax[j + 1] = arrayMax[j];
            j = j - 1;
        }
        arrayMax[j + 1] = key;
    }
    i = 0;
    j = 0;
    while(i < numMin && j < numMax)
    {
        if(arrayMin[i] > arrayMax[j])
            j++;
        else if(arrayMin[i] < arrayMax[j])
            i++;
        else
        {
            returnArray[(*returnSize)++] = arrayMin[i];
            ;
            i++;
            j++;
        }
    }
    if(*returnSize == 0)
        return NULL;
    else
        return returnArray;
}
