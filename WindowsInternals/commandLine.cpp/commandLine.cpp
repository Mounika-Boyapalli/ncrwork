#include<iostream>
#include<Windows.h>
using namespace std;
int _cdecl main()
{
	LPWSTR * szArglist;
	int nArgs, i;
	szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	if (szArglist == NULL)
		wcout << "CommandLineToArgvW failed" << endl;
	else
		for (i = 0; i < nArgs; i++)
			wcout << " " << szArglist[i] << endl;
	system("pause");
	return 0;
}