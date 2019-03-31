#include<iostream>
#include <string.h>
using namespace std;
class Student
{
protected: char *student_name;
		   int rno;
		   int marks[3];
		   float avg;
public: Student()
		{
			student_name = NULL;
			rno = 0;
			marks[0] = 0;
			marks[1] = 0;
			marks[2] = 0;
			avg = 0;
		}
		Student(char* name, int roll, int* m)
		{
			int i = 0;
			student_name = new char[strlen(name) + 1];
			strcpy_s(student_name,strlen(name)+1, name);
			rno = roll;
			for (i = 0; i < 3; i++)
			{
				marks[i] = m[i];
			}
		}
		void get_data()
		{
			int i = 0;
			char temp_name[30];
			cout << "Enter the students name" << endl;
			cin >> temp_name;
			student_name = new char[strlen(temp_name) + 1];
			strcpy_s(student_name,strlen(temp_name)+1,temp_name);
			cout << "Enter the roll number" << endl;
			cin >> rno;
			cout << "Enter the marks" << endl;
			for (i = 0; i < 3; i++)
			{
				cin >> marks[i];
			}
		}
		void display_details()
		{
			cout << endl;
			cout << "Student name :  " << student_name << endl;
			cout << "Roll number :  " << rno << endl;
			cout << "Marks :  " << marks[0] << "  " << marks[1] << "  " << marks[2] << endl;
		}
		virtual void calculate_avg()
		{
			cout << "In Student Class" << endl;
		}
		// virtual void calculate_avg() = 0;
};
class Engineering : public Student
{
public : void calculate_avg()
		 {
			float sum = 0;
			sum = marks[0] + marks[1] + marks[2];
			avg = sum / 3;
			cout << "Domain :  Engineering" << endl;
			cout << "Average :  " << avg << endl;
			if (avg >= 80 && avg <= 100)
				cout << "Grade : A " << endl;
			else if (avg >= 60 && avg <= 79)
				cout << "Grade : B " << endl;
			else if (avg >= 40 && avg <= 59)
				cout << "Grade : C " << endl;
			else
				cout << "FAIL" << endl;
		 }
};
class Medicine : public Student
{
public: void calculate_avg()
		{
			float sum = 0;
			sum = marks[0] + marks[1] + marks[2];
			avg = sum / 3;
			cout << "Domain :  Medicine" << endl;
			cout << "Average :  " << avg << endl;
			if (avg >= 70 && avg <= 100)
				cout << "Grade : A " << endl;
			else if (avg >= 60 && avg <= 69)
				cout << "Grade : B " << endl;
			else if (avg >= 50 && avg <= 59)
				cout << "Grade : C " << endl;
			else if(avg >= 50 && avg <= 59)
				cout << "Grade : D " << endl;
			else
				cout << "FAIL" << endl;
		}
};
class Science : public Student
{
public: void calculate_avg()
		{
			float sum = 0;
			sum = marks[0] + marks[1] + marks[2];
			avg = sum / 3;
			cout << "Domain :  Science" << endl;
			cout << "Average :  " << avg << endl;
			if (avg >= 90 && avg <= 100)
				cout << "Grade : A+ " << endl;
			else if (avg >= 80 && avg <= 89)
				cout << "Grade : A " << endl;
			else if (avg >= 70 && avg <= 79)
				cout << "Grade : B+ " << endl;
			else if (avg >= 60 && avg <= 69)
				cout << "Grade : B " << endl;
			else if (avg >= 50 && avg <= 59)
				cout << "Grade : C " << endl;
			else if (avg >= 40 && avg <= 49)
				cout << "Grade : D " << endl;
			else
				cout << "FAIL" << endl;
		}
};

int main()
{
	Student *student_obj[4], stud_obj;
	Engineering e_obj;
	Medicine m_obj;
	Science s_obj;
	student_obj[0] = &stud_obj;
	student_obj[1] = &e_obj;
	student_obj[2] = &m_obj;
	student_obj[3] = &s_obj;
	int index = 0;
	for (index = 0; index <= 3; index++)
	{
		student_obj[index]->get_data();
	}
	for (index = 0; index <= 3; index++)
	{
		student_obj[index]->display_details();
		student_obj[index]->calculate_avg();
	}
	system("pause");
	return 0;
}