#include<stdio.h>
#include<string.h>
int main()
{
	char string[80] = "NULL";
	int index = 0, length = 0, alpha = 0, numeric = 0, tab = 0, space = 0;
	printf("\nEnter the string");
	scanf_s("%[^\n]s", string,strlen(string));
	for (length = 0; string[length]; length++);
	for (index = 0; index < length; index++)
	{
		if (string[index] == 9)
			tab++;
		else if ((string[index] <= 57) && (string[index] >= 48))
			numeric++;
		else if (((string[index] >= 65) && (string[index] <= 90)) || ((string[index] >= 97) && (string[index] <= 122)))
			alpha++;
		else if (string[index] == ' ')
			space++;
	}
	printf("\nAlphabets=%d\nDigits=%d\nTab=%d\nSpace=%d", alpha, numeric, tab, space);
	getch();
	return 0;
}