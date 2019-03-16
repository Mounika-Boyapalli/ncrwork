#include<stdio.h>
int main()
{
	char s[50];
	int len, i;
	printf("\nEnter a string");
	scanf_s("%[^\n]s", s);
	for (len = 0; s[len]; len++);
	for (i = 0; i < len; i++)
	{
		if ((s[i] <= 65) && (s[i] >= 90))
			s[i] = s[i] + 32;
		if ((s[i] <= 97) && (s[i] >= 122))
			s[i] = s[i] - 32;
	}
	printf("%[^\n]s", s);
	getch();
	return 0;
}