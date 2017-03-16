/**
 * 461. Hamming Distance
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

 * Given two integers x and y, calculate the Hamming distance.

 * Note:
 * 0 ≤ x, y < 231.

 * Example:

 * Input: x = 1, y = 4

 * Output: 2

 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑

 * The above arrows point to positions where the corresponding bits are different.
 **/
int hammingDistance(int x, int y) {
    int dis = 0;
	int temp = x^y ; // 做异或
	while(temp != 0)
	{
		if(temp & 0x01 == 1)
			++dis;
		temp = temp >> 1; //右移一位
	}
	
	
	return dis;
}
