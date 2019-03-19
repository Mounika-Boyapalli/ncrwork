#include<iostream>
#include<string.h>
using namespace std;
class string_c
{
	char *name;
	int length;
public: string_c()
		{
			name = NULL;
			length = 0;
		}
		string_c(const char *s)
		{
			length = strlen(s);
			name = (char *)malloc(sizeof(char)*(length + 1));
			strcpy(name, s);
		}
		string_c(const string_c &temp)
		{
			length = temp.length;
			name = new char[length + 1];
			strcpy(name,temp.name);
		}
		void display()
		{
			cout << name << endl;
			cout << "Length of the string is " << length << endl;
		}
		~string_c()
		{
			if (name != NULL)
			{
				free(name);
				cout << "Deleted";
			}
		}
};

int main()
{
	string_c string1("mounika");
	string_c string2(string1);
	string1.display();
	string2.display();
	string1.~string_c();
	system("pause");
	return 0;
}
