#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#define BUFFSIZE 100
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE] = L"Kernel object is a memory block.";
	hFile = CreateFile(argv[1],
		               GENERIC_WRITE,
					   0,
					   NULL,
					   CREATE_ALWAYS,
					   FILE_ATTRIBUTE_NORMAL,
					   NULL
					  );
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File cannot be opened. Error [%d]"), GetLastError());
		return FALSE;
	}
	_tprintf(_T("File is opened.\n"));
	DWORD dwNbw;
	BOOL ret = WriteFile(hFile,
					     buffer,
						 sizeof(buffer),
						 &dwNbw,
						 NULL
						);
	if (ret == 0)
	{
		_tprintf(_T("File can't be written in. Error [%d]"), GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hFile);
	getchar();
	return TRUE;
}