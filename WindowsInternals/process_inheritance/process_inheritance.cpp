#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	_SECURITY_ATTRIBUTES s1;
	ZeroMemory(&s1, sizeof(s1));
	s1.nLength = sizeof(s1);
	s1.lpSecurityDescriptor = NULL;
	s1.bInheritHandle = TRUE;
	HANDLE hEvent = CreateEvent(&s1, FALSE, FALSE, TEXT("newevent"));
	if (hEvent == NULL)
	{
		printf("\nEvent couldnot be created. Error [%ld]", GetLastError());
		getchar();
		return FALSE;
	}
	else
		printf("\nEvent is created.");
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
		TRUE,
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
	getchar();
	return 0;
}