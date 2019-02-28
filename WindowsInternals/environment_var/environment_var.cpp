#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<tchar.h>
using namespace std;
void DumpEnvString(PTSTR pEnvBlock[])
{
	int curr = 0;
	PTSTR *pElement = (PTSTR *)pEnvBlock;
	PTSTR pcurrent = NULL;
	while (pElement != NULL)
	{
		pcurrent = (PTSTR)(*pElement);
		if (pcurrent == NULL)
			pElement = NULL;
		else
		{
			_tprintf(TEXT("[%u]%s\n"), curr, pcurrent);
			curr++;
			pElement++;
		}
	}
}
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvString(env);
	TCHAR envVarString0[] = TEXT("%SystemRoot%");
	TCHAR envVarString1[] = TEXT("%windir%");
	TCHAR envVarString2[] = TEXT("%user%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarString0, buffer, MAX_PATH);
	if (!ret)
	{
		cout << GetLastError() << endl;
		return 0;
	}
	else
	{
		wcout << buffer << endl;
	}
	ret = ExpandEnvironmentStrings(envVarString1, buffer, MAX_PATH);
	if (!ret)
	{
		cout << GetLastError() << endl;
		return 0;
	}
	else
	{
		wcout << buffer << endl;
	}
	system("pause");
	return 0;
}