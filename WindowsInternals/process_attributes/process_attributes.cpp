#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	BOOL bProcess;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	bProcess = CreateProcess(NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	);
	if (bProcess == 0)
	{
		printf("\nCreate Process Error [%d]", GetLastError());
		getchar();
		return FALSE;
	}
	else
		printf("\nProcess is created");
	printf("\nCurrent process ID is %ld", GetCurrentProcessId());
	printf("\nProcess ID of specified process is %ld", GetProcessId(pi.hProcess));
	printf("\nCurrent thread ID is %ld", GetCurrentThreadId());
	printf("\nThread Id of spexified process is %ld", GetThreadId(pi.hThread));
	printf("\nID of Process running the specified thread is %ld", GetProcessIdOfThread(pi.hThread));
	getchar();
	return 0;
}
