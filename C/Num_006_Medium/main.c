/**
 * 6. ZigZag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:

 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
 char* convert(char* s, int numRows) {
    int strLen = 0;
	if(s == NULL || s[0] == '\0' || s[1] == '\0' || numRows == 1)
		return s;
	
	// 获取s长度
	while(s[strLen] != '\0')
		++strLen;
	
	char *result = (char *)malloc(sizeof(char) * (strLen + 1));
	int i;
	int num_write = 0;
	int Move = 2*numRows - 2;
	for(i = 0; i < numRows; ++i)
	{
		int local = i;
		int move_row = 2*i;
		while(local < strLen)
		{
			result[num_write] = s[local];
			++num_write;
			
			move_row = Move - move_row;
			if( move_row == 0)
				move_row = Move;
			local = local + move_row;

		}
	}
	result[strLen] = '\0';
	return result;
}