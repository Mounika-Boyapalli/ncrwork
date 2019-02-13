#include <stdio.h>
void count()
{
	FILE *fp;
	char ch;
	int alpha = 0, digits = 0, sc = 0, spaces = 0;
	fp = fopen("abc.c", "r");
	while ((ch = getchar(fp)) != EOF)
	{
		if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
		{
			alpha++;
		}
		else if ((ch >= '0') && (ch <= '9'))
		{
			digits++;
		}
		else if (ch == ' ')
		{
			spaces++;
		}
		else
		{
			sc++;
		}
	}
	fclose(fp);
	printf("\nNumber of alphabets is %d", alpha);
	printf("\nNumber of digits is %d", digits);
	printf("\nNumber of spaces is %d", spaces);
	printf("\nNumber of special characters is %d", sc);

}