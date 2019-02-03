#include<stdio.h>
#define INT_BITS 32
int rotate(int n, int d); 
int main()
{
	int n,d,s;
	printf("\nEnter number and shift");
	scanf("%d %d",&n,&d);
	s= rotate(n, d);
	printf("After Right Rotation = %d",s);
	return 0;
}

int rotate(int n,int d)
{
	return (n>>d) | (n<< (INT_BITS - d));
}