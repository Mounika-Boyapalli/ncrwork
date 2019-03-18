#include<iostream>
using namespace std;
class student
{
	char *studentName;
	int sub1;
	int sub2;
	int sub3;
public:	void set_data(char* name, int m1, int m2, int m3)
		{
			studentName = name;
			sub1 = m1;
			sub2 = m2;
			sub3 = m3;
		}
		float calculateAverage()
		{
			float avg = 0, sum = 0;
			sum = sub1 + sub2 + sub3;
			avg = sum / 3;
			return avg;
		}
		int computeGrade(float a)
		{
			if (a <= 100)
			{
				if (a > 60)
					return 1;
				else if (50 < a < 60)
					return 2;
				else if (40 < a < 50)
					return 3;
				else
					return 4;
			}
			else
				return -1;
		}
		void display(float a, int g)
		{
			cout << "Student Name  :    " << studentName << endl;
			cout << "Marks in Sub1 :    " << sub1 << endl;
			cout << "Marks in Sub2 :    " << sub2 << endl;
			cout << "Marks in Sub3 :    " << sub3 << endl;
			cout << "Average Marks :    " << a << endl;
			
			if(g == 1)
				cout << "Grade         :    First Class" << endl;
			else if(g == 2)
				cout << "Grade         :    Second Class" << endl;
			else if(g == 3)
				cout << "Grade         :    Third Class" << endl;
			else if(g == 4)
				cout << "Grade         :    Fail" << endl;
		}
};

int main()
{

	student student_1;
	char name[30];
	int marks_1 = 0, marks_2 = 0, marks_3 = 0, grade = 0;
	float average = 0;
	cout << "Enter name the name of the student" << endl;
	cin >> name;
	cout << "Enter marks" << endl;
	cin >> marks_1 >> marks_2 >> marks_3;
	student_1.set_data(name, marks_1, marks_2, marks_3);
	average = student_1.calculateAverage();
	grade = student_1.computeGrade(average);
	cout << endl;
	student_1.display(average, grade);
	system("pause");
	return 0;
}