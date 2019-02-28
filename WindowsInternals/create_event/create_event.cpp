#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int main()
{
	HANDLE g_hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("newevent"));
	if (g_hEvent == NULL)
		printf("\nEvent cannot be created. Error %d", GetLastError());
	else
		printf("\nEvent created.");
	//CloseHandle(g_hEvent);
	getchar();
	return 1;
}