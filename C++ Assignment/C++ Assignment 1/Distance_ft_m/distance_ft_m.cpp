#include<iostream>
using namespace std;
class distance2;
class distance1
{
	int meter;
	int centi;
public: distance1(int m, int c)
		{
			meter = m;
			centi = c;
		}
		friend void add(distance1, distance2);
};
class distance2
{
	int inch;
	int feet;
public: distance2(int f, int i)
		{
			feet = f;
			inch = i;
		}
		friend void add(distance1, distance2);
};
void add(distance1 d1, distance2 d2)
{
	float total_cm = 0, total_in = 0;
	int div = 0;
	int choice = 0;
	total_cm = 100 * d1.meter + d1.centi + 12 * 2.54*d2.feet + 2.54*d2.inch;//convert to centimeters
	total_in = d1.centi / 2.54 + d2.inch + 12 * d2.feet + 100 * d1.meter / 2.54;//covert to inches
	cout << "Enter choice" << endl << "1. In m-cm" << endl << "2. In ft-in" << endl;
	cin >> choice;
	if (choice == 1)
	{
		div = total_cm / 100;
		cout << div << " meters ";
		div = (int)total_cm % 100;
		cout << div << " centimeters" << endl;
	}
	if (choice == 2)
	{
		div = total_in / 12;
		cout << div << " feet ";
		div = (int)total_in % 12;
		cout << div << " inches" << endl;
	}
}
int main()
{
	distance1 d1(3, 50);
	distance2 d2(12, 2);
	add(d1, d2);
	system("pause");
	return 0;

}