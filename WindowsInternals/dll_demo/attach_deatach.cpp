#include<Windows.h>
#include<stdio.h>
#include "dll_demo.h"
BOOL WINAPI Dllmain(HANDLE hand, DWORD msg, LPVOID res)
{
	switch (msg)
	{
	case DLL_PROCESS_ATTACH: printf("\nDLL attached");
		                     break;
	case DLL_PROCESS_DETACH: printf("\nDLL deattached");
		                     break;
	}
	return TRUE;
}