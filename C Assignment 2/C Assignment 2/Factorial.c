#include <stdio.h>
int main()
{
	int input = 0, index = 0, factorial = 1;
	printf("\nEnter the number");
	scanf_s("%d", &input);
	for (index = input; index >= 1; index--)
	{
		factorial = factorial * index;
	}
	printf("\n%d is the factorial of %d", factorial, input);
	getch();
	return 0;
}