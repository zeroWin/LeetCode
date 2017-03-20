/**
 * 136. Single Number
 * Given an array of integers, every element appears twice except for one. Find that single one.
 **/
 
 
 
int singleNumber(int* nums, int numsSize) {
   int result = 0;
   int i;
   for(i = 0; i < numsSize; ++i)
   {
	   result ^= nums[i];
   }
   return result;
}