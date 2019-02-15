#include<iostream>
using namespace std;
class Employee
{
	int empno;
	char name[20];
	int salary;
public: void set_data()
        {
	        cin >> empno;
	        cin >> name;
	        cin >> salary;
        }
	    friend ostream& operator<< (ostream& cout, Employee c);
};

ostream& operator<< (ostream& cout, Employee c)
{
	cout << "Employee name " << c.name << endl;
	cout << "Employee number " << c.empno << endl;
	cout << "Salary " << c.salary << endl;
	return (cout);
}



int main()
{
	Employee s1[6];
	int k, n=5;
	for (k = 0; k < n; k++)
	{
		s1[k].set_data();
	}
	for (k = 0; k < n; k++)
	{
		cout << s1[k] << endl;
	}
	system("pause");
	return 0;
}