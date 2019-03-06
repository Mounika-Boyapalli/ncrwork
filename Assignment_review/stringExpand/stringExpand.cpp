#include<iostream>
using namespace std;
char* expand(char*, char*);
int main()
{
	char *input_string = NULL, *output_string = NULL;
	int in_length = 0, out_length = 0;
	cout << "Enter the length of the string" << endl;
	cin >> in_length;
	input_string = new char[in_length];
	cout << "Enter the string" << endl;
	cin >> input_string;
	cout << "Enter the expected length of the second string" << endl;
	cin >> out_length;
	output_string = new char[out_length];
	output_string = expand(input_string, output_string);
	cout << output_string << endl;
	system("pause");
	return 0;
}
char* expand(char* s1, char* s2)
{
	int i, j=0, k;
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] == '-')
		{
			for (k = s2[j - 1] + 1; k < s1[i + 1]; k++)
			{
				s2[j] = k;
				j++;
			}
		}
		else
		{
			s2[j] = s1[i];
			j++;
		}
	}
	s2[j] = '\0';
	return s2;
}