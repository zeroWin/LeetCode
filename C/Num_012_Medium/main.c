/**
 * 12. Integer to Roman
 * Given an integer, convert it to a roman numeral.

 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */
 
 // 用数组比用switch的方法更好。
char* intToRoman(int num) {
    char *result;
	char *roman1;
	char *roman2;
	char *roman3;
	char *roman4;
	int i;
	for(i = 3; i >= 0; --i)
	{
		int num_temp = (num/(int)pow(10,i))%10;
		if(i == 3)
		{
			switch(num_temp)
			{
				case 0:roman1 = "";break;
				case 1:roman1 = "M"; break;
				case 2:roman1 = "MM"; break;
				case 3:roman1 = "MMM"; break;
			}
		}
		
		if(i == 2)
		{
			switch(num_temp)
			{
				case 0:roman2 = "";break;
				case 1:roman2 = "C";break;
				case 2:roman2 = "CC";break;
				case 3:roman2 = "CCC";break;
				case 4:roman2 = "CD";break;
				case 5:roman2 = "D";break;
				case 6:roman2 = "DC";break;
				case 7:roman2 = "DCC";break;
				case 8:roman2 = "DCCC";break;
				case 9:roman2 = "CM";break;
			}
		}
		if(i == 1)
		{
			switch(num_temp)
			{
				case 0:roman3 = "";break;
				case 1:roman3 = "X";break;
				case 2:roman3 = "XX";break;
				case 3:roman3 = "XXX";break;
				case 4:roman3 = "XL";break;
				case 5:roman3 = "L";break;
				case 6:roman3 = "LX";break;
				case 7:roman3 = "LXX";break;
				case 8:roman3 = "LXXX";break;
				case 9:roman3 = "XC";break;
			}
		}
		if(i == 0)
		{
			switch(num_temp)
			{
				case 0:roman4 = "";break;
				case 1:roman4 = "I";break;
				case 2:roman4 = "II";break;
				case 3:roman4 = "III";break;
				case 4:roman4 = "IV";break;
				case 5:roman4 = "V";break;
				case 6:roman4 = "VI";break;
				case 7:roman4 = "VII";break;
				case 8:roman4 = "VIII";break;
				case 9:roman4 = "IX";break;
			}
		}		
	}
		
	int strLen = strlen(roman1)+strlen(roman2)+strlen(roman3)+strlen(roman4);
	result = (char *)malloc(sizeof(char)*(strLen+1));
	
	strcpy(result,roman1);
	strcat(result,roman2);
	strcat(result,roman3);
	strcat(result,roman4);
	
	
	return result;
}

















