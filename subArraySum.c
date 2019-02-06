#include <stdio.h>
int main()
{
	int n, i, j, flag=0, sum=0, x, a[100];
	printf("\nEnter the number of elements");
	scanf_s("%d",&n);
	printf("\nEnter the array");
	for(i=0;i<n;i++)
	{
		scanf_s("%d",&a[i]);
	}
	printf("\nEnter the sum");
	scanf_s("%d",&x);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			sum = sum + a[j];
			if(sum == x)
			{
				printf("%d %d",i,j);
				flag = 1;
			}
			else if(sum > x)
			{
				break;
			}
		}
		sum = 0;
	}
	if(flag == 0)
	{
		for(i=n-1;i>=0;i--)
		{
			for(j=i;j>=0;j--)
			{
				sum = sum + a[j];
				if( sum == x)
				{
					printf("%d %d",j,i);
					break;
				}
			}
			sum = 0;
		}
	}
	getch();
	return 0;
}					
