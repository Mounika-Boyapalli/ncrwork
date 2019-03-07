#include <stdio.h>
int main()
{
	int input = 0, remainder = 0, temp_var = 0, sum = 0;
	printf("\nEnter a number");
	scanf_s("%d", &input);
	temp_var = input;
	while (input != 0)
	{
		remainder = input % 10;
		sum = sum + remainder * remainder * remainder;
		input = input / 10;
	}
	if (temp_var == sum)
	{
		printf("\n%d is an armstrong number", temp_var);
	}
	else
	{
		printf("\n%d is not an armstrong number", temp_var);
	}
	getch();
	return 0;
}