#include<Windows.h>
#include"dll_demo.h"
int add(int nVariable1, int nVariable2)
{
	int nResult = 0;
	nResult = nVariable1 + nVariable2;
	return nResult;
}