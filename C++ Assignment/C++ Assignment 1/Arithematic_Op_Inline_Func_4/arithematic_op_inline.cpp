#include<iostream>
using namespace std;
inline int addition(int x, int y)
{
	return (x + y);
}
inline int subtraction(int x, int y)
{
	return (x - y);
}
inline int multiplication(int x, int y)
{
	return (x * y);
}
inline int division(int x, int y)
{
	return (x / y);
}
int main()
{
	int variable_1 = 0, variable_2 = 0, sum = 0, diff = 0, product = 0, quotient = 0;
	cout << "Enter the numbers" << endl;
	cin >> variable_1 >> variable_2;
	sum = addition(variable_1, variable_2);
	diff = subtraction(variable_1, variable_2);
	product = multiplication(variable_1, variable_2);
	quotient = division(variable_1, variable_2);
	cout << "Sum= " << sum << endl;
	cout << "Difference= " << diff << endl;
	cout << "Product= " << product << endl;
	cout << "Quotient= " << quotient << endl;
	system("pause");
	return 0;
}