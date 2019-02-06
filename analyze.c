#include <stdio.h>
int main()
{
	int n, i, x[20];
	printf("\nEnter the number");
	scanf_s("%d", &n);
	printf("\nEnter the array");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &x[i]);
	}

	printf("\nx is %d", x);
	printf("\n(x+2) is %d", x + 2);
	printf("\n*x is %d", *x);
	printf("\n(*x+2) is %d", (*x + 2));
	printf("\n*(x+2) is %d", *(x + 2));
	getch();
	return 0;
}