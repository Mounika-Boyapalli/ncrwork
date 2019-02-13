#include<iostream>
using namespace std;
class Time
{
	int hours;
	int minutes;
	int seconds;
public:  Time()
{
	hours = minutes = seconds = 0;
}
		 Time(int x, int y, int z)
		 {
			 hours = x;
			 minutes = y;
			 seconds = z;
		 }
		 void get_time()
		 {
			 cin >> hours >> minutes >> seconds;
		 }
		 void print_time()
		 {
			 cout << hours << ":" << minutes << ":" << seconds << endl;
		 }
		 void add_time(Time t1, Time t2)
		 {
			 seconds = t1.seconds + t2.seconds;
			 minutes = t1.minutes + t2.minutes;
			 hours = t1.hours + t2.hours;
			 while (seconds >= 60)
			 {
				 seconds = seconds - 60;
				 minutes = minutes + 1;
			 }
			 while (minutes >= 60)
			 {
				 minutes = minutes - 60;
				 hours = hours + 1;
			 }

		 }
};

int main()
{
	int h, m, s, h1, m1, s1;
	cout << "Enter the hours, minutes and seconds";
	cin >> h >> m >> s;
	cout << "Enter the hours, minutes and seconds";
	cin >> h1 >> m1 >> s1;
	Time c1(h, m, s), c2(h1, m1, s1), c3;
	c3.add_time(c1, c2);
	c3.print_time();
	system("pause");
	return 0;
}