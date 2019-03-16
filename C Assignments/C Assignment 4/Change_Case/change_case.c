#include<stdio.h>
int main()
{
	char input_string[50];
	int len, i;
	printf("\nEnter a string");
	scanf_s("%[^\n]s", input_string);
	for (len = 0; input_string[len]; len++);
	for (i = 0; i < len; i++)
	{
		if ((input_string[i] <= 65) && (input_string[i] >= 90))
			input_string[i] = input_string[i] + 32;
		if ((input_string[i] <= 97) && (input_string[i] >= 122))
			input_string[i] = input_string[i] - 32;
	}
	printf("%[^\n]s", input_string);
	getch();
	return 0;
}