#include<iostream>
using namespace std;
class Student
{
	int rno;
	char name[20];
	int m1;
	int m2;
	int m3;
	int total;
	char grade;
    public: friend ostream& operator<< (ostream& cout, Student c);
			friend istream& operator>> (istream& cin, Student &c);
			friend void generate_results (Student[], int n);
};

ostream& operator<< (ostream& cout, Student c)
{
	cout << "Student name " << c.name << endl;
	cout << "Student roll number " << c.rno << endl;
	cout << "Marks " << c.m1 << " " << c.m2 << " " << c.m3 << endl;
	cout << "Total Marks " << c.total << endl;
	cout << "Grade " << c.grade << endl;
	return (cout);
}

istream& operator >> (istream& cin, Student &c)
{
	cin >> c.name;
	cin >> c.rno;
	cin >> c.m1;
	cin >> c.m2;
	cin >> c.m3;
	return (cin);
}

void generate_results(Student s[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		s[i].total = s[i].m1 + s[i].m2 + s[i].m3;
		if (s[i].total / 3 >= 80)
			s[i].grade = 'A';
		else if (s[i].total / 3 >= 60)
			s[i].grade = 'B';
		else if (s[i].total / 3 >= 40)
			s[i].grade = 'C';
		else
			s[i].grade = 'F';
	}
}
int main()
{
	Student s1[3];
	int k,n;
	cout << "Enter the number";
	cin >> n;
	for (k = 0; k < n; k++)
	{
		cin >> s1[k];
	}
	generate_results(s1,n);
	for (k = 0; k < n; k++)
	{
		cout << s1[k] << endl;
	}
	system("pause");
	return 0;
}