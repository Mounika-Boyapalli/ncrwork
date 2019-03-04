#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
DWORD WINAPI thread_func(LPVOID lparam)
{
	printf("\nthread_func is executed\n");
	return 0;
}
int main()
{
	DWORD dwThreadId;;
	HANDLE hThread;
	HANDLE handle_array;
	hThread = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadId);
	if (hThread == NULL)
	{
		printf("\nUnable to create thread. Error [%d]", GetLastError());
		getchar();
		return FALSE;
	}
	handle_array = hThread;
	CloseHandle(hThread);
	getchar();
	return 0;
}