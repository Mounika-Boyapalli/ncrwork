#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 0; i < 1000; i++)
	{
		printf("\ni=%d", i);
		Sleep(5000);
	}
	return 0;
}
int main()
{
	DWORD dwThreadId1, dwThreadId2;
	HANDLE hThread1, hThread2;
	HANDLE handle_array[2];
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, NULL, &dwThreadId1);
    if (hThread1 == NULL)
	{
		printf("\nUnable to create thread. Error [%d]", GetLastError());
		getchar();
		return FALSE;
	}
	handle_array[0] = hThread1;
	CloseHandle(hThread1);
	hThread2 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadId2);
	if (hThread2 == NULL)
	{
		printf("\nUnable to create thread. Error [%d]", GetLastError());
		getchar();
		return FALSE;
	}
	handle_array[1] = hThread2;
	CloseHandle(hThread2);
	getchar();
	return 0;
}