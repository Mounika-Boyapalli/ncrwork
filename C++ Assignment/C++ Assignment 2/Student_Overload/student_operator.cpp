#include<iostream>
using namespace std;
class Student
{
	int rno;
	char name[20];
	int marks_1;
	int marks_2;
	int marks_3;
	int total;
	char grade;
public: friend ostream& operator<< (ostream& cout, Student c);
		friend istream& operator>> (istream& cin, Student &c);
		friend void generate_results(Student[], int n);
};

ostream& operator<< (ostream& cout, Student c)
{
	cout << "Student name " << c.name << endl;
	cout << "Student roll number " << c.rno << endl;
	cout << "Marks " << c.marks_1 << " " << c.marks_2 << " " << c.marks_3 << endl;
	cout << "Total Marks " << c.total << endl;
	cout << "Grade " << c.grade << endl;
	return (cout);
}

istream& operator >> (istream& cin, Student &c)
{
	cout << "Enter the name" << endl;
	cin >> c.name;
	cout << "Enter rollno" << endl;
	cin >> c.rno;
	cout << "Enter 3 subjects marks:" << endl;
	cin >> c.marks_1;
	cin >> c.marks_2;
	cin >> c.marks_3;
	return (cin);
}

void generate_results(Student s[], int n)
{
	int index_1 = 0;
	for (index_1 = 0; index_1 < n; index_1++)
	{
		s[index_1].total = s[index_1].marks_1 + s[index_1].marks_2 + s[index_1].marks_3;
		if (s[index_1].total / 3 >= 80)
			s[index_1].grade = 'A';
		else if (s[index_1].total / 3 >= 60)
			s[index_1].grade = 'B';
		else if (s[index_1].total / 3 >= 40)
			s[index_1].grade = 'C';
		else
			s[index_1].grade = 'F';
	}
}
int main()
{
	Student s1[5];
	int index = 0, number_of_students = 0;
	cout << "Enter the number";
	cin >> number_of_students;
	for (index = 0; index < number_of_students; index++)
	{
		cout << "Enter details of Student" << index+1 << endl;
		cin >> s1[index];
	}
	generate_results(s1, number_of_students);
	for (index = 0; index < number_of_students; index++)
	{
		cout << s1[index] << endl;
	}
	system("pause");
	return 0;
}