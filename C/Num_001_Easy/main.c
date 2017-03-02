/**
 * 1. Two Sum
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.

 * You may assume that each input would have exactly one solution, and you may not use the same element twice.

 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,

 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */
 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int *result = (int *)malloc(sizeof(int)*2);
	//����Ӧ���ж�һЩ����״������
	//1.nums == NULL
	//2.numsSize�Ĵ�С���Լ���numsʵ�������Ƿ�ƥ�䡣
	//������Ŀ˵�ˣ�һ���н⣬������Щ�����ж���
	int num1_local,num2_local;
	int target_temp;
	int flag = 0;
	for(num1_local = 0;num1_local < numsSize - 1; ++num1_local)
	{
		target_temp = target - nums[num1_local];
		for(num2_local = num1_local + 1;num2_local < numsSize; ++num2_local)
		{
			if(target_temp == nums[num2_local])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	result[0] = num1_local;
	result[1] = num2_local;
	
	return result;
}
 
 
 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int i = 0;
	int j = numsSize - 1;
	int *returnArray = (int *)malloc(sizeof(int)*2);
	int num_temp;
	while (i < numsSize)
	{
		num_temp = target - nums[i];
		for (j = i + 1; j < numsSize; ++j)
		{
		    if (num_temp == nums[j])
		    {
		        returnArray[0] = i;
		        returnArray[1] = j;
		        return returnArray;
		        
		    }
		    
		}
		++i;
	}
    return returnArray;
}