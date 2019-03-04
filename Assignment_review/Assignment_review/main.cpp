#include<iostream>
using namespace std;
int main()
{
	char *expression = NULL;
	int length = 0;
	cout << "Enter the length of the expression to be evaluated" << endl;
	cin >> length;
	expression = new char[length];
	cout << "Enter the expression to be evaluated" << endl;
	cin >> expression;
	system("pause");
	return 0;
}