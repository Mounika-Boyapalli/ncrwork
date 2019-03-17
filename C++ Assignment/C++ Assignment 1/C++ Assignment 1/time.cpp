#include<iostream>
using namespace std;
//defining time class with hours, minutes and seconds as parameters
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
	int hr2 = 0, min2 = 0, sec2 = 0, hr1 = 0, min1 = 0, sec1 = 0;
	cout << "Enter the hours, minutes and seconds";
	cin >> hr1 >> min1 >> sec1;
	cout << "Enter the hours, minutes and seconds";
	cin >> hr2 >> min2 >> sec2;
	Time object_1(hr1, min1, sec1), object_2(hr2, min2, sec2), object_3;
	object_3.add_time(object_1, object_2);
	object_3.print_time();
	system("pause");
	return 0;
}