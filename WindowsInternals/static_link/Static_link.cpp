#include<iostream>
#include"MathFunc.h"
using namespace std;
int main()
{
	int nVariable1 = 10, nVariable2 = 8;
	cout << " Sum is " << MathFunc::MathFunc::Add(nVariable1, nVariable2) << endl;
	cout << " Difference is " << MathFunc::MathFunc::Sub(nVariable1, nVariable2) << endl;
	getchar();
	return 0;
}