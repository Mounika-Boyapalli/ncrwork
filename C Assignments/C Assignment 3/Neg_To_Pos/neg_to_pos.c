#include <stdio.h>
int main()
{
	int index1 = 0, index2 = 0, temp_var = 0, num = 0, array[20];
	printf("\nEnter the number");
	scanf_s("%d", &num);
	printf("\nEnter the array");
	for (index1 = 0; index1 < num; index1++)
	{
		scanf_s("%d", &array[index1]);
	}
	for (index1 = 0; index1 < num; index1++)
	{
		for (index2 = index1 + 1; index2 < num; index2++)
		{
			if (array[index1] > array[index2])
			{
				temp_var = array[index1];
				array[index1] = array[index2];
				array[index2] = temp_var;
			}
		}
	}

	for (index1 = 0; index1 < num; index1++)
	{
		printf("%d ", array[index1]);
	}
	getch();
	return 0;
}