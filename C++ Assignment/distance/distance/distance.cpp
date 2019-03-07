#include<iostream>
using namespace std;
class distance2;
class distance1
{
	int m;
	int cm;
	int m1;
	int cm1;
	public: distance1(int x,int y)
			{
				m = x;
			    cm = y;
			}
			void print_dist()
			{
				cout << "Distance in meters and centimeters is " << m1 << cm1 << endl;
			}
			friend void add_distance(distance1  , distance2 );

};
class distance2
{
	int ft;
	int in;
	int ft1;
	int in1;
	public: distance2(int x, int y)
			{
		        ft = x;
				in = y;
			}
			void print_dist()
			{
				cout << "Distance in feet and inches is " << ft1 << in1 << endl;
			}
			friend void add_distance(distance1, distance2);
};

void add_distance(distance1 n1, distance2 n2)
{
	int cm2, in2;
	cm2 = ((n2.in)*2.54) + ((n2.ft) * 12 * 2.54);
	n1.m1 = cm2 / 100;
	n1.cm1 = cm2 % 100;
	in2 = ((n1.cm / 2.54)) + ((n1.m) * 100 / 2.54);
	n2.in1 = in2 % 12;
	n2.ft1 = in2 / 12;
}
int main()
{
	int a, b, p, q;
	cout << "Enter the distance in meters and centimeters";
	cin >> a >> b;
	cout << "Enter the distance in feet and inches";
	cin >> p >> q;
	distance1 d1(a,b);
	distance2 d2(p,q);
	d1.print_dist;
	d2.print_dist;
	system("pause");
	return 0;
}