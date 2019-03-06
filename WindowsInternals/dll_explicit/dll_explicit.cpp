#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include"dll_demo.h"
//typedef int(*add1) (int, int);
//typedef int(*sub1) (int, int);
typedef int(*MYPROC) (int, int);
int _tmain()
{
	HMODULE hdll;
	MYPROC ADD, SUB;
	/*add1 ptr1;
	sub1 ptr2;*/
	int nVariable1 = 10, nVariable2 = 8;
	int nSum = 0, nDiff = 0;
	hdll = LoadLibraryEx(TEXT("C:\\Users\\sdf\\source\\repos\\ncrwork2\\WindowsInternals\\Debug\\dll_demo.dll"), NULL, NULL);
	if (hdll == NULL)
	{
		printf("\nHdll failed. Error [%ld]", GetLastError());
		getchar();
		return FALSE;
	}
	ADD = (MYPROC)GetProcAddress(hdll, (LPCSTR)"add");
	if (ADD != NULL)
	{
		nSum = ADD(nVariable1, nVariable2);
		printf("\nSum is %d", nSum);
	}
	else
	{
		printf("\nError in ADD. Error [%ld]", GetLastError());
		getchar();
		return FALSE;
	}
	SUB = (MYPROC)GetProcAddress(hdll, (LPCSTR)"sub");
	if (SUB != NULL)
	{
		nDiff = SUB(nVariable1, nVariable2);
		printf("\nDifference is %d", nDiff);
	}
	else
	{
		printf("\nError in SUB. Error [%ld]", GetLastError());
		getchar();
		return FALSE;
	}
	FreeLibrary(hdll);
	getchar();
	return 0;
}