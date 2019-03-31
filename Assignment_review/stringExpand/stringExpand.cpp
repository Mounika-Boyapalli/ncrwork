#include<iostream>
using namespace std;
char* expand(char*, char*);
int main()
{
	//definitions and initializations
	char *shorthand_string = NULL, *expanded_string = NULL;
	int in_length = 0, out_length = 0;

	cout << "Enter the length of the string" << endl;
	cin >> in_length;
	//allocating memory to the string
	shorthand_string = new char[in_length];
	cout << "Enter the string" << endl;
	cin >> shorthand_string;

	cout << "Enter the expected length of the second string" << endl;
	cin >> out_length;
	expanded_string = new char[out_length];

	//allocating memory to the expanded string
	expanded_string = expand(shorthand_string, expanded_string);
	
	if (expanded_string[0] != '\0')
	{
		cout << expanded_string << endl;
	}
	//delete expanded_string;
	//delete shorthand_string;
	system("pause");
	return 0;
}

//expands shorthand to full length text
char* expand(char* in_string, char* out_string)
{
	//definations and initializations
	int index1 = 0, index2 = 0, index3 = 0;

	for (index1 = 0; in_string[index1]; index1++)
	{
		if (in_string[index1] == '-')
		{
			if (in_string[index1 + 1] == '-')
			{
				cout << "Invalid String! Two - are not allowed" << endl;
				out_string[0] = '\0';
				return out_string;
			}
			else if (in_string[index1 - 1] > in_string[index1 + 1])
			{
				cout << "Invalid String! Order is wrong" << endl;
				out_string[0] = '\0';
				return out_string;
			}
			else if ( ( (!isalpha(in_string[index1 + 1])) && (isalpha(in_string[index1 - 1]) ) ) || (isalpha(in_string[index1 + 1])) && (!isalpha(in_string[index1 - 1]) ) )
			{
				cout << "Invalid String! Number- Alpha mismatch" << endl;
				out_string[0] = '\0';
				return out_string;
			}
			else
			{
				for (index3 = out_string[index2 - 1] + 1; index3 < in_string[index1 + 1]; index3++)
				{
					out_string[index2] = index3;
					index2++;
				}
			}
		}
		else
		{
			out_string[index2] = in_string[index1];
			index2++;
		}
	}
	out_string[index2] = '\0';
	return out_string;
}