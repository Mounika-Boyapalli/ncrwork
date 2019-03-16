#include<stdio.h>
#define INT_BITS 32
void rotate(int n, int d);
int main()
{
	int input = 0, shift = 0, output = 0;
	printf("\nEnter number and shift");
	scanf_s("%d %d", &input, &shift);
	rotate(input, shift);
	//printf("After Right Rotation = %d", output);
	getch();
	return 0;
}

void rotate(int n, int d)
{
	printf("\nShifted output is %d",(n >> d) | (n << (INT_BITS - d)));
}