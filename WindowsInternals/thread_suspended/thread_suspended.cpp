#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 0; i < 1000; i++)
	{
		printf("\ni=%d", i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD dwThreadId1;
	HANDLE hThread1;
	HANDLE handle_array;
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, CREATE_SUSPENDED, &dwThreadId1);
	if (hThread1 == NULL)
	{
		printf("\nUnable to create thread. Error [%d]", GetLastError());
		getchar();
		return FALSE;
	}
	else
		printf("\nThread Created.");
	Sleep(5000);
	ResumeThread(hThread1);
	handle_array = hThread1;
	CloseHandle(hThread1);
	getchar();
	return 0;
}