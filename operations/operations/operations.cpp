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
	int a, b, s, d, p, q;
	cout << "Enter the numbers" << endl;
	cin >> a >> b;
	s = addition(a, b);
	d = subtraction(a, b);
	p = multiplication(a, b);
	q = division(a, b);
	cout << "Sum= " << s << endl;
	cout << "Difference= " << d << endl;
	cout << "Product= " << p << endl;
	cout << "Quotient= " << q << endl;
	system("pause");
	return 0;
}