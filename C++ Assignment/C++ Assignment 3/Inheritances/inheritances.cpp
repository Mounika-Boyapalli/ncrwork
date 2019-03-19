#include<iostream>
#include<string.h>
using namespace std;
class person
{
	char *name;
	int age;
public: person()
		{
			name = NULL;
			age = 0;
		}
		person(char *name_temp, int age_temp)
		{
			name = new char[strlen(name_temp)];
			strcpy(name, name_temp);
			age = age_temp;
		}
		void getPersonalDetails()
		{
			char string_temp[30];
			cout << "Enter Name and Age" << endl;
			cin >> string_temp;
			cin >> age;
			name = new char[strlen(string_temp)];
			strcpy(name, string_temp);
			//free (string_temp);
		}
		void displayPersonalDetails()
		{
			cout << "Name = " << name << endl << "Age = " << age << endl;
		}
		~person()
		{
			if (name != NULL)
			delete name;
		}
};
class Physique : virtual public person
{
	int height;
	int weight;
public: Physique()
	    {
			height = weight = 0;
		}
		Physique(int ht, int wt)
		{
			height = ht;
			weight = wt;
		}
		void getPhysique()
		{
			cout << "Enter height and weight " << endl;
			cin >> height >> weight;
		}
		void displayPhysique()
		{
			cout << "Height = " << height << endl << "Weight = " << weight << endl;
		}
};
class Family :virtual public person
{
	int numChildren;
	char *religion;
public: Family()
		{
			religion = NULL;
			numChildren = 0;
		}
		Family(int nC, char *rel)
		{
			numChildren = nC;
			religion = new char[strlen(rel)];
			strcpy(religion, rel);
		}
		void getFamily()
		{
			char s[25];
			cout << "Enter number of children and religion" << endl;
			cin >> numChildren;
			cin >> s;
			religion = new char[strlen(s)];
			strcpy(religion, s);
			//delete s;
		}
		void displayFamily()
		{
			cout << "Number of children = " << numChildren << endl << "Religion = " << religion << endl;
		}
		~Family()
		{
			if (religion != NULL)
				delete religion;
		}
};

class Employee :public Family, public Physique
{
	int empno;
	int salary;
public: Employee()
		{
			empno = salary = 0;
		}
		Employee(int eno, int sal)
		{
			empno = eno;
			salary = sal;
		}
		void getEmployee()
		{
			cout << "Enter employee number and salary " << endl;
			cin >> empno >> salary;
		}
		void displayEmployee()
		{
			cout << "Employee number = " << empno << endl << "Salary = " << salary << endl;
		}
};
int main()
{
	Employee employee_1;
	employee_1.getPersonalDetails();
	employee_1.getPhysique();
	employee_1.getFamily();
	employee_1.getEmployee();
	employee_1.displayPersonalDetails();
	employee_1.displayPhysique();
	employee_1.displayFamily();
	employee_1.displayEmployee();
	system("pause");
	return 0;
}