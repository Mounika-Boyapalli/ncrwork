#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
long g_var = 0;
DWORD WINAPI inc_func1(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_var, 1);
	g_var++;
	return 0;
}
DWORD WINAPI inc_func2(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_var, 1);
	g_var++;
	return 0;
}
int main()
{
	DWORD dwThreadId1, dwThreadId2;
	HANDLE hThread1, hThread2;
	HANDLE handle_array[2];
	while (1)
	{
		g_var = 0;
		hThread1 = CreateThread(NULL, 0, inc_func1, NULL, 0, &dwThreadId1);
		if (hThread1 == NULL)
		{
			printf("\nUnable to create thread. Error [%d]", GetLastError());
			getchar();
			return FALSE;
		}
		handle_array[0] = hThread1;
		CloseHandle(hThread1);
		hThread2 = CreateThread(NULL, 0, inc_func2, NULL, 0, &dwThreadId2);
		if (hThread2 == NULL)
		{
			printf("\nUnable to create thread. Error [%d]", GetLastError());
			getchar();
			return FALSE;
		}
		handle_array[1] = hThread2;
		CloseHandle(hThread2);
		printf("\nValue of global variable is %d", g_var);
		if (g_var == 1)
		{
			printf("\nSynchronization Issue");
			break;
		}
	}
	getchar();
	return 0;
}