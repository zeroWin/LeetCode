/**
 * 11. Container With Most Water
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

 * Note: You may not slant the container and n is at least 2.
 *
 */

// 暴力查找timeout
int maxArea(int* height, int heightSize) {
    int result = 0;
	
	int i;
	int temp;
	
	for(i = 0; i < heightSize; ++i)
	{
		for(temp = 0; temp < i; ++temp)
		{
			int container = (height[i]-height[temp] > 0?height[temp]:height[i]) * (i - temp);
			if (container > result)
				result = container;
		}
	}
	return result;
}


// 这么简单的一道题，怎么就是没有想出来。
// 盛水的多少呀。。。从两边开始算。。。
int maxArea(int* height, int heightSize) {
    int result = 0;
	int i = 0;
	int j = heightSize - 1;
	while(i < j)
	{
		int temp = (j - i)*((height[i] < height[j])?height[i]:height[j]);
		if(height[i] < height[j])
			++i;
		else
			--j;
		if(temp > result)
			result = temp;
	}	
	return result;
}















