#include<iostream>
#include<string.h>
using namespace std;
class mystring
{
	//private datamembers
	char* name;
	int length;
	//public member functions
public: //default constructor
	mystring()
	{
		name = NULL;
		length = 0;
	}
	//single parameterized constructor 
	mystring(int n)
	{
		name = NULL;
		length = 0;
	}
	//single parameterized constructor
	mystring(char* s)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
		length = strlen(name);
	}
	//double parameterized constructor
	mystring(char* s, int n)
	{
		name = new char[n + 1];
		strcpy(name, s);
		length = n;
	}
	mystring(const mystring &s)
	{
		length = s.length;
		name = new char[length + 1];
		strcpy(name, s.name);
	}
	//overloading concatenation operation
	mystring operator+(mystring s1)
	{
		mystring str_obj;
		str_obj.length = length + s1.length + 1;
		str_obj.name = new char[str_obj.length];
		strcpy(str_obj.name, name);
		strcat(str_obj.name, s1.name);
		return (str_obj);
	}
	//overloading equate operator
	mystring operator=(mystring s1)
	{
		if (name != NULL)
			delete name;
		name = new char[strlen(s1.name)];
		strcpy(name, s1.name);
		length = s1.length;
		return *(this);
	}
	//overloading compare operator
	mystring operator<(mystring s1)
	{
		
	}
	//destructor
	~mystring()
	{
		if (name != NULL)
			delete name;
	}
	//friend functions of >> and << operators
	friend istream& operator>>(istream& cin, mystring &);
	friend ostream& operator<<(ostream& cout, mystring);
	friend void sort();
};
istream& operator>>(istream& cin, mystring &s1)
{
	char temp_string[20];
	cout << "Enter the string " << endl;
	cin >> temp_string;
	s1.length = strlen(temp_string);
	s1.name = new char[strlen(temp_string) + 1];
	strcpy(s1.name, temp_string);
	s1.length = strlen(s1.name);
	return (cin);
}
ostream& operator<<(ostream& cout, mystring s1)
{
	cout << s1.name << endl;
	return (cout);
}
void sort()
{
	mystring string_s[10];
	int no = 0, index_1 = 0, index_2 = 0, length = 0;
	cout << "Enter the number of strings" << endl;
	cin >> no;
	for (index_1 = 0; index_1 < no; index_1++)
	{
		cin >> string_s[index_1];
	}
	for (index_1 = 0; index_1 < no; index_1++)
	{
		for (index_2 = 0; index_2 < no - index_1; index_2++)
		{
			
		}
	}
}
int main()
{
	mystring string[5];
	system("pause");
	return 0;
}