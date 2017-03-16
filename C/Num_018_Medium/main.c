/**
 * 18. 4Sum
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 * Note: The solution set must not contain duplicate quadruplets.

 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 int comInc(const void *a,const void *b)
 {
	 return *(int *)a - *(int *)b;
 }
 
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int **result = NULL;
	int arrayRow = 0;
	*returnSize = 0;
	if(numsSize < 4)
		return result;
	
	// 快速排序
	qsort(nums,numsSize,sizeof(nums[0]),comInc);
	
	int i;
	int flag = 0;
	for(i = 0; i < numsSize - 3; ++i) // 去重
	{
		if(i > 0 && nums[i] == nums[i - 1])
			continue;
		
		int j;
		for(j = i + 1; j < numsSize - 2; ++j)	// 去重
		{
			if(j > i + 1 && nums[j] == nums[j - 1])
				continue;
			
			// 求2Sum
			int st = j + 1;
			int ed = numsSize - 1;
			while(st < ed)
			{
				int sum = nums[i] + nums[j] + nums[st] + nums[ed];
				if(sum == target)
				{
					++arrayRow;
					if(flag == 0) // 第一次
					{
						result = (int **)malloc(sizeof(int *)*arrayRow);
						flag = 1;
					}
					else
						result = (int **)realloc(result,sizeof(int *)*arrayRow);
					
					result[arrayRow-1] = (int *)malloc(sizeof(int) * 4);
					result[arrayRow-1][0] = nums[i];
					result[arrayRow-1][1] = nums[j];
					result[arrayRow-1][2] = nums[st];
					result[arrayRow-1][3] = nums[ed];
					
					while(st < ed && nums[st + 1] == nums[st]) ++st;
					while(st < ed && nums[ed - 1] == nums[ed]) --ed;
				}
				(sum > target)?--ed:++st;
			}
			
		}
	}
	
	*returnSize = arrayRow;
	return result;
}










