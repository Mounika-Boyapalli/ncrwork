#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
	CHAR ansi_array[] = "ANSI";
	WCHAR wide_array[] = L"WIDE";
	int ret1, ret2, size1, size2;
	ret1 = IsTextUnicode(ansi_array, strlen(ansi_array), NULL);
	if (ret1 == 1)
		cout << "ansi_array is unicode" << endl;
	else if (ret1 == 0)
		cout << "ansi_array is not unicode" << endl;
	ret2 = IsTextUnicode(wide_array, wcslen(wide_array), NULL);
	if (ret2 == 1)
		cout << "wide_array is unicode" << endl;
	else if (ret2 == 0)
		cout << "wide_array is not unicode" << endl;
	size1 = WideCharToMultiByte(CP_UTF8, 0, wide_array, -1, NULL, 0, NULL, NULL);
	CHAR *wide_ansi_array = new CHAR[size1];
	WideCharToMultiByte(CP_UTF8, 0, wide_array, -1, wide_ansi_array, size1, NULL, NULL);
	cout << "The string converted from wide to ansi is " << wide_ansi_array << endl;
	size2 = MultiByteToWideChar(CP_UTF8, 0, ansi_array, -1, NULL, 0);
	WCHAR *ansi_wide_array = new WCHAR[size2];
	MultiByteToWideChar(CP_UTF8, 0, ansi_array, -1, ansi_wide_array, size2);
	wcout << "The string converted from ansi to wide is " << ansi_wide_array << endl;
	DWORD n = GetLastError();
	cout << "Error is " << n << endl;
	return 0;
}