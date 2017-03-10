/**
 * 15. 3Sum
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

 * Note: The solution set must not contain duplicate triplets.

 * For example, given array S = [-1, 0, 1, 2, -1, -4],

 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // 第一种方法一开始占用空间过多。
 // 消除了占用的空间又超时了。

 int compInc(const void *a,const void *b)
 {
	 return *(int *)a - *(int *)b;
 }
 
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int arraySize = 0;
	int i,j,k;	
	int **result = NULL;
	// 快排
	qsort(nums,numsSize,sizeof(nums[0]),compInc);
	
	
	for(i = 0; i < numsSize - 2; ++i)
	{
		if(i > 0 && nums[i] == nums[i - 1]) // 重复的不用再找了
			continue;
		int find2sum = 0 - nums[i];
		for(j = i + 1; j < numsSize - 1; ++j)
		{
			if(j > i + 1 && nums[j] == nums[j - 1]) // 重复的不用再找了
				continue;
			int findNum = find2sum - nums[j];
			//找findNum，可以用二分，就顺序查找吧
			for(k = j + 1;k < numsSize; ++k)
			{
				if(findNum == nums[k])
				{
					++arraySize;
					break;
				}
			}
		}
	}
	result = (int **)malloc(sizeof(int *)*arraySize);
	arraySize = 0;
	for(i = 0; i < numsSize - 2; ++i)
	{
		if(i > 0 && nums[i] == nums[i - 1]) // 重复的不用再找了
			continue;
		int find2sum = 0 - nums[i];
		for(j = i + 1; j < numsSize - 1; ++j)
		{
			if(j > i + 1 && nums[j] == nums[j - 1]) // 重复的不用再找了
				continue;
			int findNum = find2sum - nums[j];
			//找findNum，可以用二分，就顺序查找吧
			for(k = j + 1;k < numsSize; ++k)
			{
				if(findNum == nums[k])
				{
				    result[arraySize] = (int *)malloc(sizeof(int)*3);
				    result[arraySize][0] = nums[i];
				    result[arraySize][1] = nums[j];
				    result[arraySize][2] = nums[k];
					++arraySize;
					break;
				}
			}
		}
	}
	
	*returnSize = arraySize;
	return result;
}




// 第二种方法相比第一种方法并没有什么本质上的变化
// 优化有两点
// 1.查找改为2分查找，复杂度为n^2 * lgn;之前为n^3
// 2.就是开辟空间从循环两次变为1次。

// 和他们的思路第一个循环的判断思想是一样的，查找2sum又没有想到顺序的查找方法，明明之前
// 已经做过一遍的。

 int compInc(const void *a,const void *b)
 {
	 return *(int *)a - *(int *)b;
 }
 
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int arraySize = 0;
	int i,j;	
	int **result = NULL;
	// 快排
	qsort(nums,numsSize,sizeof(nums[0]),compInc);
	
	int flag = 0;
	for(i = 0; i < numsSize - 2; ++i)
	{
		if(i > 0 && nums[i] == nums[i - 1]) // 重复的不用再找了
			continue;
		int find2sum = 0 - nums[i];
		for(j = i + 1; j < numsSize - 1; ++j)
		{
			if(j > i + 1 && nums[j] == nums[j - 1]) // 重复的不用再找了
				continue;
			int findNum = find2sum - nums[j];
			//找findNum，可以用二分
			int *res;
			res = (int *)bsearch(&findNum,nums+j+1,numsSize-j-1,sizeof(nums[j+1]),compInc);
			if(res)
			{
				if(flag == 0)
				{
					result = (int **)malloc(sizeof(int *)*(arraySize + 1));
					flag = 1;
				}
				else
					result = (int **)realloc(result,sizeof(int *)*(arraySize + 1));
				result[arraySize] = (int *)malloc(sizeof(int)*3);
				result[arraySize][0] = nums[i];
				result[arraySize][1] = nums[j];
				result[arraySize][2] = *res;
				++arraySize;
			}
		}
	}
	*returnSize = arraySize;
	return result;
}







