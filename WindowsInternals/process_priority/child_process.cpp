#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
DWORD WINAPI threadFunc(LPVOID lpParam)
{
	printf("\nIn threadFunc");
	return 0;
}
int _main()
{
	printf("\nPriority before changing priority is %ld", GetPriorityClass(GetCurrentProcess()));
	SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
	printf("\nPriority after changing priority is %ld", GetPriorityClass(GetCurrentProcess()));
	DWORD dwThreadId;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, threadFunc, NULL, 0, &dwThreadId);
	if (hThread != NULL)
		printf("\nThread is created");
	else
		printf("\nError in creating thread. Error [%ld]", GetLastError());
	BOOL ret = SetThreadPriority(hThread, THREAD_PRIORITY_LOWEST);
	if (ret == 0)
		printf("\nPriority couldnt be set to the thread. Error [%ld] ", GetLastError());
	else
		printf("\nPriority set");
	CloseHandle(hThread);
	getchar();
	return 0;
}