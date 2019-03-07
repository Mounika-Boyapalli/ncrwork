#include <stdio.h>
int main()
{
	int array[20];
	int index1 = 0, index2 = 0, temp_var = 0, avg = 0, min = 0, max = 0, pos = 0, sum = 0, length = 0;
	for (index1 = 0;; index1++)
	{
		scanf_s("%d", &array[index1]);
		if (array[index1] <= 0)
			break;
	}
	for (index1 = 0;; index1++)
	{
		if (array[index1] > 0)
		{
			length++;
		}
		else
		{
			break;
		}
	}
	pos = length;
	for (index1 = 0; index1 < length; index1++)
	{
		sum = sum + array[index1];
		for (index2 = index1 + 1; index2 < length; index2++)
		{
			if (array[index1] > array[index2])
			{
				temp_var = array[index1];
				array[index1] = array[index2];
				array[index2] = temp_var;
			}
		}
	}
	max = array[length - 1];
	min = array[0];
	avg = sum / length;
	printf("\nNumber of positive values = %d\nMinimum value = %d\nMaximum value = %d\nAverage value = %d", pos, min, max, avg);
	getch();
	return 0;
}
