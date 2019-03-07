#include<iostream>
using namespace std;
class point
{
	float x;
	float y;
public: point()
{
	x = 0;
	y = 0;
}
		void get_point()
		{
			cin >> x >> y;
		}
		friend float addd(point, point);
};

float addd(point m, point n)
{
	float d;
	d = sqrt((m.x - n.x)*(m.x - n.x) + (m.y - n.y)*(m.y - n.y));
	return d;
}
int main()
{
	point p1, p2;
	float distance;
	int p, q, a, b;
	cout << "Enter the coordinates of first point" << endl;
	p1.get_point();
	cout << "Enter the coordinates of second point" << endl;
	p2.get_point();
	distance = addd(p1, p2);
	cout << "Distance is " << distance << endl;
	system("pause");
	return 0;
}