#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int g_nSum;
int COUNT = 50;
CRITICAL_SECTION g_cs;
DWORD WINAPI thread_fun1(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	g_nSum++;
	LeaveCriticalSection(&g_cs);
	return g_nSum;
}
DWORD WINAPI thread_fun2(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	g_nSum++;
	LeaveCriticalSection(&g_cs);
	return g_nSum;
}
int main()
{
	DWORD thId1, thId2;
	HANDLE hThread1, hThread2;
	HANDLE arr[2];
	InitializeCriticalSection(&g_cs);
	int cnt = 0;
	while (1)
	{
		cnt++;
		g_nSum = 0;
		hThread1 = CreateThread(NULL,
			0,
			thread_fun1,
			NULL,
			0,
			&thId1
		);
		if (hThread1 == NULL)
		{
			printf("Unable to create thread %d\n", GetLastError());
			getchar();
			return 0;
		}
		hThread2 = CreateThread(NULL,
			0,
			thread_fun2,
			NULL,
			0,
			&thId2
		);
		if (hThread2 == NULL)
		{
			printf("Unable to create thread %d\n", GetLastError());
			getchar();
			return 0;
		}
		arr[0] = hThread1;
		arr[1] = hThread2;
		WaitForMultipleObjects(2, arr, TRUE, INFINITE);
		printf("%d\n", g_nSum);
		if (cnt == 25)
			break;
	}
	//WaitForSingleObject(hThread, 1000);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	getchar();
	return 0;
}