#include<iostream>
#include<string.h>
using namespace std;
class employee
{
	char *name;
	int salary;
public: employee()
		{
			name = NULL;
			salary = 0;
			cout << "default constructor" << endl;
		}
		employee(char* n)
		{
			name = n;
			//strcpy_s(name, 5, n);
			cout << "parameterized constructor with single argument" << endl;
		}
		employee(int sal)
		{
			salary = sal;
			cout << "parameterized constructor with single argument" << endl;
		}
		employee(char* n, int sal)
		{
			//strcpy_s(name, 5, n);
			name = n;
			salary = sal;
			cout << "parameterized constructor with two arguments" << endl;
		}
		employee(employee &e)
		{
			name = e.name;
			salary = e.salary;
			cout << "copy contrustor";
		}
		void display()
		{
			cout << "Name is " << name << endl;
			cout << "Salary is " << salary << endl;
		}
		~employee()
		{
			free(name);
			cout << "destructor" << endl;
		}
};

int main()
{
	char *emp_name;
	emp_name = new char[8];
	cout << "Enter your name" << endl;
	cin >> emp_name;
	employee emp_1, emp_2(50000), emp_3(emp_name), emp_4(emp_name,50000), emp_5(emp_4);
	cout << endl;
	/*emp_1.display();
	cout << endl;
	emp_2.display();
	cout << endl;
	emp_3.display();
	cout << endl;
	emp_4.display();*/
	int size1 = 0, size2 = 0, size3 = 0;
	size1 = sizeof(emp_3);
	size2 = sizeof(emp_4);
	size3 = sizeof(emp_5);
	cout << "Size of emp_3 is " << size1 << endl;
	cout << "Size of emp_4 is " << size2 << endl;
	cout << "Size of emp_5 is " << size3 << endl;
	system("pause");
	return 0;

}