#include<iostream>
using namespace std;
class student
{
public:
	char studentName[30];
	char grade;
	int sub1;
	int sub2;
	int sub3;
	void get_data()
	{
		
	}
	
};
class CollegeCourse
{
	student s1;
	int len, sum, m1, m2, m3;
	float avg;
	char gr[15];
public: 
	    void set_Data(char *s, int m1, int m2,int m3)
        {
	         strcpy_s(s1.studentName, s);
        }
		void calculateAverage()
		{
			sum = s1.sub1 + s1.sub2 + s1.sub3;
			avg = sum / 3;
			
		}
		void display()
		{
			cout << "Student Details" << endl;
			cout << "Name: " << s1.studentName << endl;
			cout << "Marks in Subject1: " << m1 << endl;
			cout << "Marks in Subject2: " << m2 << endl;
			cout << "Marks in Subject3: " << m3 << endl;
			cout << "Average: " << avg << endl;
		}
		void ComputeGrade()
		{
			if (avg > 60)
			{
				cout << "First Class" << endl;
			}
			else if ((50 < avg) && (avg < 60))
			{
				cout << "Second Class" << endl;
			}
			else if((40 < avg) && (avg < 50))
			{
				cout << "Third Class" << endl;
			}
			else
			{
				cout << "Fail" << endl;
			}
		}
		
};

int main()
{
	
	student c;
	CollegeCourse c1;
	char stu[30];
	int h1, h2, h3;
	cout << "Enter name";
	cin >> stu;
	cout << "Enter marks" << endl;
	cin >> h1 >> h2 >> h3;
	
	c1.set_Data(stu,h1,h2,h3);
	c1.calculateAverage();
	c1.display();
	c1.ComputeGrade();

	system("pause");
	return 0;
}