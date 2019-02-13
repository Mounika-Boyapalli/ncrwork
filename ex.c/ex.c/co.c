#include <stdio.h>
void count();
int main()
{
	count();
	getch();
	return 0;
}
void count()
{
	FILE *fp;                                            //defining file pointer
	char ch;                                             //defining character variable
	int alpha = 0, digits = 0, sc = 0, spaces = 0;       //initializing count values
	fp = fopen_s(&"abc.c","abc.c", "r");                            //file is opened
	while ((ch = getchar(fp)) != EOF)                      //file is read char by char
	{
		if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))    //condition for checking if alphabet
		{
			alpha++;
		}
		else if ((ch >= '0') && (ch <= '9'))    //condition for checking if digit
		{
			digits++;
		}
		else if (ch == ' ')                    //condition for checking if space
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