#include<iostream>
using namespace std;
class polar
{
	float angle;
	float radius;

public: /*polar()
		{
			angle = 0;
			radius = 0;
		}*/
		static int count;
		void get_data(float x, float y)
		{
			angle = x;
			radius = y;
		}
		static void inc_count()
		{
			count++;
			cout << "Count is " << count << endl;
		}
};
int polar::count = 0;

int main()
{
	float angle_1 = 0, radius_1 = 0, angle_2 = 0, radius_2 = 0;
	polar point_1, point_2;
	cout << "Enter the angle and radius" << endl;
	cin >> angle_1 >> radius_1;
	point_1.get_data(angle_1, radius_1);
	polar::inc_count();
	cout << "Enter the angle and radius" << endl;
	cin >> angle_2 >> radius_2;
	point_2.get_data(angle_2, radius_2);
	polar::inc_count();
	system("pause");
	return 0;
}