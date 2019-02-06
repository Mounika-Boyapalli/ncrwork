#include <stdio.h>
int main()
{
	int n,i,rev=0;
	scanf_s("%d",&n);
	while(n>0)
	{
		i=n%10;
		rev = rev*10+i;
		n=n/10;
	}
	printf("Reversed number is %d",rev);
	getch();
}
