#include<iostream>
using namespace std;
class Employee
{
	int empno;
	char name[20];
	int salary;
public: void set_data()
		{
			cout << "Enter employee id" << endl;
			cin >> empno;
			cout << "Enter name of employee" << endl;
			cin >> name;
			cout << "Enter the salary of employee" << endl;
			cin >> salary;
		}
		friend ostream& operator<< (ostream& cout, Employee c);
};

ostream& operator<< (ostream& cout, Employee c)
{
	cout << "Employee name: " << c.name << endl;
	cout << "Employee number: " << c.empno << endl;
	cout << "Salary: " << c.salary << endl;
	return (cout);
}
int main()
{
	Employee s1[6];
	int index = 0, number_of_employees = 5;
	for (index = 0; index < number_of_employees; index++)
	{
		cout << "Enter details of employee" << index + 1 << endl;
		s1[index].set_data();
	}
	cout << endl;
	for (index = 0; index < number_of_employees; index++)
	{
		cout << s1[index] << endl;
	}
	system("pause");
	return 0;
}