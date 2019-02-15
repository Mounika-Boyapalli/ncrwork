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
				cout << count<< endl;
			}

};
int polar::count = 0;

int main()
{
	float a, b, m, n;
	polar p1, p2;
	cout << "Enter the angle and radius" << endl;
	cin >> a >> b;
	p1.get_data(a, b);
	polar::inc_count();
	cout << "Enter the angle and radius" << endl;
	cin >> m >> n;
	p2.get_data(m, n);
	polar::inc_count();
	system("pause");
	return 0;
}