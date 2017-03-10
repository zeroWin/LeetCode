/**
 * 7. Reverse Integer
 * Reverse digits of an integer.

 * Example1: x = 123, return 321
 * Example2: x = -123, return -321

 * Note:
 * The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
 *
 */

 // 这个题做的非常不好。
 // 首先，最基本的掉转数字顺序的方法都忘了
 // 其次，没有考虑到比较大小应该转换成int型

int reverse(int x) {

	long result = 0;

	while (x != 0)
	{
		result = result * 10 + (x % 10);
		if(result > (int)0x7FFFFFFF || result < (int)0x80000000)
			return 0;
		x /= 10;
	}

	return (int)result;

}
