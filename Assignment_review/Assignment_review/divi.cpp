#include<iostream>
using namespace std;
int divi(int var1, int var2)
{
	extern int result;
		if (var2 == 0)
			return -999;
		else
		{
			result = var1 / var2;
			return (result);
		}
}