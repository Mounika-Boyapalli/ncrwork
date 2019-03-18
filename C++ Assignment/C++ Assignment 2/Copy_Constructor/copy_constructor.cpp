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
			strcpy_s(name,length,s);
		}
		/*string_c(const string &temp)
		{
			length = temp.length;
			name = (char *)malloc(sizeof(char)*(length + 1));
			strcpy_s(name,length,temp.name);
		}*/
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
	//string_c string2(string1);
	string1.display();
	//string2.display();
	string1.~string_c();
	system("pause");
	return 0;
}
