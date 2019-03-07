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
	//delete input_string;
	//delete output_string;
	system("pause");
	return 0;
}
char* expand(char* in_string, char* out_string)
{
	int index1 = 0, index2 = 0, index3 = 0, flag = 0;
	for (index1 = 0; in_string[index1]; index1++)
	{
		if (in_string[index1] == '-')
		{
			if (in_string[index1 - 1] > in_string[index1 + 1])
			{
				cout << "Invalid input" << endl;
				flag = 1;
				break;
			}
			for (index3 = out_string[index2 - 1] + 1; index3 < in_string[index1 + 1]; index3++)
			{
				out_string[index2] = index3;
				index2++;
			}
		}
		else
		{
			out_string[index2] = in_string[index1];
			index2++;
		}
	}
	if (flag == 1)
		out_string[0] = '\0';
	else
		out_string[index2] = '\0';
	return out_string;
}