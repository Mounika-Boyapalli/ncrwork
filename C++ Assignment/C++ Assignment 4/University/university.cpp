#include<iostream>
using namespace std;
class University
{
	char *universityName;
	char *deptName;
	char *personName;
public: University()
		{
			universityName  =	NULL;
			deptName		=	NULL;
			personName		=	NULL;
		}
		University(char* uni_name, char* dept_name, char* name)
		{
			universityName  =  new char[strlen(uni_name) + 1];
			deptName	    =  new char[strlen(dept_name) + 1];
			personName		=  new char[strlen(name) + 1];
			universityName	=  uni_name;
			deptName		=  dept_name;
			personName		=  name;
		}
		virtual void get_data()
		{
			char temp_string[50];

			cout << "Enter the name of the university " << endl;
			cin >> temp_string;
			universityName = new char[strlen(temp_string) + 1];
			universityName = temp_string;

			cout << "Enter the department name" << endl;
			cin >> temp_string;
			deptName = new char[strlen(temp_string) + 1];
			deptName = temp_string;

			cout << "Enter the name of the person to whom the project is assigned" << endl;
			cin >> temp_string;
			personName = new char[strlen(temp_string) + 1];
			personName = temp_string;
		}
		virtual void display_info()
		{
			cout << "Name of the University is " << universityName << endl;
			cout << "Name of the department is " << deptName << endl;
			cout << "Name of the person to whom project is assigned " << personName << endl;
		}
};
class Company
{
	char *companyName;
	int noOfEngineers;
	double amountInvested;
public: Company()
		{
			companyName		=	NULL;
			noOfEngineers	=	0;
			amountInvested	=	0;
		}
		Company(char* name, int n, double a)
		{
			companyName		=	new char[strlen(name) + 1];
			companyName		=	name;
			noOfEngineers	=	n;
			amountInvested  =	a;
		}
		virtual void get_data()
		{
			char temp_string[50];

			cout << "Enter the name of the company " << endl;
			cin >> temp_string;
			companyName = new char[strlen(temp_string) + 1];
			companyName = temp_string;

			cout << "Enter the number of engineers working on the project" << endl;
			cin >> noOfEngineers;

			cout << "Enter the amount invested by the company" << endl;
			cin >> amountInvested;
		}
		virtual void display()
		{
			cout << "Name of the Company is " << companyName << endl;
			cout << "Number of engineers is " << noOfEngineers << endl;
			cout << "Amount Invested by the company is " << amountInvested << endl;
		}
};
class Project : public University, public Company
{
	char *typeOfProject;
	float durationOfProject;
	double amountGranted;
public: Project()
		{
			typeOfProject		=	NULL;
			durationOfProject	=	0;
			amountGranted		=	0;
		}
		Project(char* name, float yr, double a)
		{
			typeOfProject		=	new char[strlen(name) + 1];
			typeOfProject		=	name;
			durationOfProject	=	yr;
			amountGranted		=	a;
		}
		void get_data()
		{
			char temp_string[50];

			cout << "Enter the type of the project " << endl;
			cin >> temp_string;
			typeOfProject = new char[strlen(temp_string) + 1];
			typeOfProject = temp_string;

			cout << "Enter the duration of the project" << endl;
			cin >> durationOfProject;

			cout << "Enter the amount granted for the project" << endl;
			cin >> amountGranted;
		}
		void display()
		{
			cout << "Type of the Project is " << typeOfProject << endl;
			cout << "Duration of the Project is " << durationOfProject << " years" << endl;
			cout << "Amount Granted for the Project is " << amountGranted << endl;
		}
};

int main()
{
	Company company;
	University uni;
	Project project;
	uni.get_data();
	company.get_data();
	project.get_data();
	uni.display_info();
	company.display();
	project.display();
	system("pause");
	return 0;
}