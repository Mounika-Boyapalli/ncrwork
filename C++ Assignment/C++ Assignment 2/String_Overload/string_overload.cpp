#include<iostream>
#include<string.h>
using namespace std;
class String
{
	char *name;
	int length;
public: String()
		{
			name = NULL;
			length = 0;
		}
		String(const char *s)
		{
			length = strlen(s);
			name = (char *)malloc(sizeof(char)*(length + 1));
			strcpy(name, s);
		}
		String(char *string1, int length1)
		{
			length = length1;
			name = new char[length + 1];
			strcpy(name, string1);
		}
		String(const String &s)
		{
			length = s.length;
			name = new char[length];
			strcpy(name, s.name);
		}
		String operator+(String s2)
		{
			String string_obj;
			string_obj.length = length + s2.length;
			if (string_obj.name == NULL)
				string_obj.name = new char[string_obj.length];
		strcpy(string_obj.name, name);
		strcat(string_obj.name, s2.name);
		return string_obj;
	}
	String operator=(String s2)
	{
		if (name == NULL)
			name = new char[strlen(s2.name)];
		strcpy(name, s2.name);
		length = s2.length;
		return *(this);
	}
	char& operator[](int i)
	{
		return name[i];
	}
	~String()
	{
		if (name != NULL)
			delete name;
	}
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, String);

};
istream& operator>>(istream& cin, String &s)
{
	char string[50];
	cout << "enter string" << endl;
	cin >> string;
	if (s.name == NULL)
		s.name = new char[strlen(string) + 1];
	strcpy(s.name, string);
	s.length = strlen(s.name);
	return cin;
}
ostream& operator<<(ostream& cout, String c)
{
	cout << "String = " << c.name << endl;
	return cout;
}
int main()
{
	String string_1, string_2, string_3;
	cin >> string_1 >> string_2;
	string_3 = string_1 + string_2;
	cout << "Concatenation of strings is " << endl;
	cout << string_3;
	cout << "the value of string1[3] = " << string_1[3] << endl;
	cout << "Equating string_2[3] and string_1[2] is " << endl;
	cout << "The value of string_2[3] before equating is " << string_2[3] << endl;
	string_2[3] = string_1[2];
	cout << "the value of string_2[3] = " << string_2[3] << endl << "the value of string_1[2] = " << string_1[2] << endl;
	string_3 = string_1 + string_2;
	cout << "Concatenation of strings is " << endl;
	cout << string_3;
	system("pause");
	return 0;
}