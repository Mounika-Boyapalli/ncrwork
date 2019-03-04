#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
DWORD dwc;
DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf("\ni=%d", i);
		Sleep(1000);
	}
	return 0;
}
int _tmain()
{
	DWORD dwThreadId1;
	HANDLE hThread1;
	HANDLE handle_array;
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadId1);
	if (hThread1 == NULL)
	{
		printf("\nUnable to create thread. Error [%d]", GetLastError());
		getchar();
		return FALSE;
	}
	else
		printf("\nThread Created.");
	handle_array = hThread1;
	WaitForSingleObject(hThread1,5000);
	TerminateThread(hThread1, dwc);
	GetExitCodeThread(hThread1, &dwc);
	printf("Exit Code Word is %ld", dwc);
	getchar();
	CloseHandle(hThread1);
	return 0;
}