#include <stdio.h>
int main()
{
	int num_ele = 0, index1 = 0, index2 = 0, flag = 0, sum = 0, req_sum = 0, array[100];
	printf("\nEnter the number of elements");
	scanf_s("%d", &num_ele);
	printf("\nEnter the array");
	for (index1 = 0; index1 < num_ele; index1++)
	{
		scanf_s("%d", &array[index1]);
	}
	printf("\nEnter the sum");
	scanf_s("%d", &req_sum);
	for (index1 = 0; index1 < num_ele; index1++)
	{
		for (index2 = index1; index2 < num_ele; index2++)
		{
			sum = sum + array[index2];
			if (sum == req_sum)
			{
				printf("%d %d", index1, index2);
				flag = 1;
			}
			else if (sum > req_sum)
			{
				break;
			}
		}
		sum = 0;
	}
	if (flag == 0)
	{
		for (index1 = num_ele - 1; index1 >= 0; index1--)
		{
			for (index2 = index1; index2 >= 0; index2--)
			{
				sum = sum + array[index2];
				if (sum == req_sum)
				{
					printf("%d %d", index2, index1);
					break;
				}
			}
			sum = 0;
		}
	}
	getch();
	return 0;
}
