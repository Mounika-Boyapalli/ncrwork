#include <stdio.h>
int main()
{
	int input = 0, remainder = 0, temp_var = 0, reverse_num = 0;
	printf("\nEnter a number");
	scanf_s("%d", &input);
	temp_var = input;
	while (input != 0)
	{
		remainder = input % 10;
		reverse_num = (reverse_num * 10) + remainder;
		input = input / 10;
	}
	if (temp_var == reverse_num)
	{
		printf("\n%d is a palindrome", temp_var);
	}
	else
	{
		printf("\n%d is not a palindrome", temp_var);
	}
	getch();
	return 0;
}