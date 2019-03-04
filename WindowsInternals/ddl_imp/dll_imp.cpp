#include<Windows.h>
#include<stdio.h>
#include"dll_demo.h"
int main()
{
	int nVariable1 = 10, nVariable2 = 8;
	int nSum = 0, nDiff = 0;
	nSum = add(nVariable1, nVariable2);
	nDiff = sub(nVariable1, nVariable2);
	printf("\nSum is %d", nSum);
	printf("\nDifference is %d", nDiff);
	getchar();
	return 0;
}