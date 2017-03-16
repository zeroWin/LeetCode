/**
 * 412. Fizz Buzz
 * Write a program that outputs the string representation of numbers from 1 to n.

 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which  * are multiples of both three and five output “FizzBuzz”.

 * Example:

 * n = 15,

 * Return:
 * [
 *     "1",
 *     "2",
 *     "Fizz",
 *     "4",
 *     "Buzz",
 *     "Fizz",
 *     "7",
 *     "8",
 *     "Fizz",
 *     "Buzz",
 *     "11",
 *     "Fizz",
 *     "13",
 *     "14",
 *     "FizzBuzz"
]
 **/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 
 // 尽量不要用%这个运算，运算速度过慢
 // fizz++和buzz++来判断这两个量是否为3和5这种方法更为快速。
char** fizzBuzz(int n, int* returnSize) {
    char ** result = (char **)malloc(sizeof(char *)*n);
	*returnSize = n;
	int i;
	for(i = 0; i < n; ++i)
	{
		if((i + 1) % 15 == 0) // 即是3又是5的倍数
		{
			result[i] = (char *)malloc(sizeof(char)*(strlen("FizzBuzz")+1));
			result[i] = strcpy(result[i],"FizzBuzz");
		}
		else if((i + 1) % 5 == 0) // 5的倍数
		{
			result[i] = (char *)malloc(sizeof(char)*(strlen("Buzz")+1));
			result[i] = strcpy(result[i],"Buzz");			
		}
		else if((i + 1) % 3 == 0) // 3的倍数
		{
			result[i] = (char *)malloc(sizeof(char)*(strlen("Fizz")+1));
			result[i] = strcpy(result[i],"Fizz");			
		}
		else
		{
			int numLen  = 0;
			int num = i + 1;
			while(num != 0)
			{
				++numLen;
				num /= 10;
			}
			result[i] = (char *)malloc(sizeof(char)*(numLen + 1));
			num = i + 1;
			int j;
			for(j = 0; j < numLen; ++j)
			{
				result[i][numLen-j-1] = (num % 10) + '0';
				num /= 10;
			}
			result[i][numLen] = '\0';
		}
	}
	return result;
}
