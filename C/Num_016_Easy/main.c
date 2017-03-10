/**
 * 16. 3Sum Closest
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 * For example, given array S = {-1 2 1 -4}, and target = 1.

 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

 // 思考不完善，出了一堆问题， 下次写代码的时候要仔细思考清楚，再写。
 int compInc(const void* a,const void* b)
 {
	 return *(int *)a - *(int *)b;
 }
 
int threeSumClosest(int* nums, int numsSize, int target) {
    
	// 快排
	qsort(nums,numsSize,sizeof(nums[0]),compInc);
	int i;
	int result;
	int flag = 0;
	for(i = 0; i < numsSize - 2; ++i)
	{
		if(i > 0 && nums[i] == nums[i - 1])
			continue;
		int target_temp = target - nums[i];
		int start = i + 1;
		int end = numsSize-1;
		while(start < end)
		{
			// 直接求三个的和不是更好，何必要分一步呢？
			int sum = nums[start]+nums[end];
			if(flag == 0) // 第一次
			{
				result = sum + nums[i];
				flag = 1;
				contine;
			}
			if(abs(target_temp - sum) < abs(target - result))
				result = sum + nums[i];
			
			if(sum - target_temp > 0) //和大
				--end;
			else if(sum - target_temp < 0) //和小
				++start;
			else
				return target;
		}
	}	
	return result;
}


int threeSumClosest(int* nums, int numsSize, int target) {
    
	// 快排
	qsort(nums,numsSize,sizeof(nums[0]),compInc);
	int i;
	int result;
	int flag = 0;
	for(i = 0; i < numsSize - 2; ++i)
	{
		if(i > 0 && nums[i] == nums[i - 1])
			continue;
		int start = i + 1;
		int end = numsSize-1;
		while(start < end)
		{
			// 直接求三个的和不是更好，何必要分一步呢？
			int sum = nums[i] + nums[start]+nums[end];
			if(flag == 0) // 第一次
			{
				result = sum;
				flag = 1;
				contine;
			}
			if(abs(target - sum) < abs(target - result))
				result = sum;
			
			if(sum - target > 0) //和大
				--end;
			else if(sum - target < 0) //和小
				++start;
			else
				return target;
		}
	}	
	return result;
}


