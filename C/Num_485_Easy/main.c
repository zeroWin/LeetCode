/**
 * 485. Max Consecutive Ones
 * Given a binary array, find the maximum number of consecutive 1s in this array.

 * Example 1:
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 *     The maximum number of consecutive 1s is 3.
 * Note:

 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 **/

 // 是有还更简单的写法
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int result = 0;
	int Temp_len = 0;
	if(numsSize > 0)
	{
		int i;
		for(i = 0;i < numsSize; ++i)
		{
			if(nums[i] == 1)
				++Temp_len;
			else
			{
				if(Temp_len > result)
					result = Temp_len;
				Temp_len = 0;
			}
		}
	}
	
	if(Temp_len > result)
		result = Temp_len;
	
	return result;
}


int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int result = 0;
	int Temp_len = 0;
	if(numsSize > 0)
	{
		int i;
		for(i = 0;i < numsSize; ++i)
		{
			Temp_len = (nums[i] == 0? 0 : ++Temp_len);
			if(Temp_len > result)
				result = Temp_len;
		}
	}
	return result;
}