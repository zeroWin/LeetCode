/**
 * 349. Intersection of Two Arrays
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 **/
#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

int main()
{
    int nums1[2] = {2,1};
    int nums2[2] = {1,1};
    int returnSize;
    int *numResult = intersection(nums1,2,nums2,2,&returnSize);
    return 0;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * 其实有些问题numArrayMax[j] = -1;这一步，数组中有-1就会不对了
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int numMax,numMin;
    int *result,*numArrayMax,*numArrayMin;
    int i,j;
    int flag = 0;
    *returnSize = 0;
    if(nums1Size > nums2Size)
    {
        numMax = nums1Size;
        numMin = nums2Size;
        numArrayMax = nums1;
        numArrayMin = nums2;
    }
    else
    {
        numMax = nums2Size;
        numMin = nums1Size;
        numArrayMax = nums2;
        numArrayMin = nums1;
    }
    result = (int *)malloc(sizeof(int)*numMin);
    for(i = 0;i < numMin; ++i)
    {
        for(j = 0;j < numMax; ++j)
        {
            if(numArrayMin[i] == numArrayMax[j])
            {
                result[*returnSize] = numArrayMax[j];
                numArrayMax[j] = -1;
                if(flag == 0)
                {
                    flag = 1;
                    *returnSize += 1;
                }
            }
        }
        flag = 0;
    }

    if(*returnSize != 0)
        return result;
    else
        return NULL;

}
