/**
 * 9. Palindrome Number
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 */
 // 有一个更加卓越的想法，就是把数字反转一遍，有点像题目7
 // 反转后如果和原数字相同，证明这个数字是回文的。
 // 没有必要用判断字符串回文的方法来判断数字是否是会问的。
 // 对于数字，有更加方便的掉转方法。
bool isPalindrome(int x) {
    if(x < 0)
		return false;
	if(x == 0)
		return true;
	
	bool result;
	// 统计数字长度
	int temp = x;
	int numLen = 0;
	while(temp != 0)
	{
		++numLen;
		temp /= 10;
	}
		
	if(numLen % 2 == 0) //偶数个
		result = isPalindromeSon(x,numLen/2,numLen/2 + 1);
	else // 奇数个 
		result = isPalindromeSon(x,(numLen+1)/2,(numLen+1)/2);
	
	return result;
}

bool isPalindromeSon(int x,int i,int j)
{
	int temp;
	int num_left;
	int num_right;
	for(temp = 0; temp < i; ++temp)
	{
		num_left = (x / (int)pow(10,j-1+temp)) % 10;
		num_right = (x % (int)pow(10,i-temp)) / (int)pow(10,i-1-temp); 
		if(num_left != num_right)
			return false;
	}
	
	return true;
}







