#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!CreateProcess(NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		HIGH_PRIORITY_CLASS,
		NULL,
		NULL,
		&si,
		&pi
	))
	{
		printf("\nCreate Process Error [%ld]", GetLastError());
		return FALSE;
	}
	else
		printf("\nProcess is created");
	/*BOOL ret1 = SetPriorityClass(pi.hProcess, HIGH_PRIORITY_CLASS);
	if (ret1 == 0)
		printf("\nError in setting priority of first proocess. Error[%ld]", GetLastError());
	CloseHandle(pi.hProcess);*/
	getchar();
	return 0;
}