#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#define BUFFSIZE 100
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	if (argc != 2)
	{
		_tprintf(_T("No filename passed"));
		getchar();
		return FALSE;
	}
	hFile = CreateFile(argv[1],
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File cannot be opened. Error [%d]"), GetLastError());
		return FALSE;
	}
	_tprintf(_T("File is opened.\n"));
	DWORD nBytesToRead;
	while (1)
	{
		ZeroMemory(buffer, sizeof(buffer));
		BOOL ret = ReadFile(hFile,
			buffer,
			BUFFSIZE,
			&nBytesToRead,
			NULL
		);
		if (ret == 0)
		{
			_tprintf(_T("File can't be read. Error [%d]"), GetLastError());
			getchar();
			return FALSE;
		}
		_tprintf(_T("%S"), buffer);
		if (nBytesToRead == 0)
			printf("\nReached EOF");
		break;
	}
	CloseHandle(hFile);
	getchar();
	return TRUE;
}
