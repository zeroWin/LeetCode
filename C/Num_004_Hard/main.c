/**
 * 4. Median of Two Sorted Arrays
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.

 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]

 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]

 * The median is (2 + 3)/2 = 2.5
 */
 
 double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if(nums1Size == 0 && nums1Size == 0)
		return nums1;
	
	if(nums1Size == 0)
	{
		if(nums2Size % 2 == 0) //偶数
			return (num2[nums2Size/2] + num2[nums2Size/2 - 1])/2;
		else
			return num2[(nums2Size-1)/2];
	}
	if(nums2Size == 0)
	{
		if(nums1Size % 2 == 0) //偶数
			return (num1[nums1Size/2] + num1[nums1Size/2 - 1])/2;
		else
			return num1[(nums1Size-1)/2];
	}
	
	int totalLen = nums1Size + nums2Size;
	int find_min = 0;
	int find_max = 0;
	if(totalLen % 2 == 0) // 偶数
	{
		find_min = totalLen/2 - 1;
		find_max = totalLen/2;		
	}
	else // 奇数
	{
		find_min = (totalLen - 1)/2;
		find_max = (totalLen - 1)/2;
	}

}



