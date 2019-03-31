#include<iostream>
using namespace std;
class pwr
{
	double base;
	double exp;
	double val;
public: pwr()
		{
			base = 0;
			exp = 0;
			val = -1;
		}
		int getVal()
		{
			return val;
		}
		pwr(double b, double e)
		{
			int i;
			base = b;
			exp = e;
			val = 1;
			for (i = exp; i > 0; i--)
				val = val * base;
		}
		pwr operator+(pwr p)
		{
			pwr temp;
			temp.val = val + p.val;
			return temp;
		}
		operator double()
		{
			cout << "Inside conversion function" << endl;
			return val;
		}
};

int main()
{
	pwr p1(2, 3), p2(3, 2), p3;
	p3 = p1 + p2;
	cout << "Sum is " << p3 << endl;
	system("pause");
	return 0;
}