#include <stdio.h>
int main()
{
	int i, j, temp, n, a[20];
	printf("\nEnter the number");
	scanf_s("%d", &n);
	printf("\nEnter the array");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	getch();
	return 0;
}