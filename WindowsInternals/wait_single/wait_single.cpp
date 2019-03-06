#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 0; i < 1000; i++)
	{
		printf("\ni=%d", i);
		Sleep(2000);
	}
	return 0;
}
int main()
{
	DWORD dwThreadId;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, thread_func, NULL, NULL, &dwThreadId);
	if (hThread == NULL)
	{
		printf("\nUnable to create thread. Error [%d]", GetLastError());
		getchar();
		return FALSE;
	}
	DWORD dwRet = WaitForSingleObject(hThread, INFINITE);
	//DWORD dwRet = WaitForSingleObject(hThread, 1000);
	switch (dwRet)
	{
	case WAIT_OBJECT_0: printf("\nThread is terminated");
					    break;
	case WAIT_TIMEOUT: printf("\nTime Interval Expired");
					   break;
	case WAIT_FAILED: printf("\nCouldnot Wait for Thread to Execute ");
					  break;
	}
	CloseHandle(hThread);