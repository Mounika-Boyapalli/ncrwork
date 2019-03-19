#include<iostream>
using namespace std;
template <class T>
int linear_search (T a[], int n, T element)
{
	int index = 0, flag = 0;
	for (index = 0; index < n; index++)
	{
		if (strcmp(a[index],element) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()
{
	linear_search <char*>;
	char **array = NULL, *key = NULL;
	int row = 0, column = 0;
	int element = 0, index_1 = 0, index_2 = 0, flag = 0, length = 0;
	cout << "Enter the length of the array" << endl;
	cin >> row;
	array = new char*[row];
	cout << "Enter the elements in arrays" << endl;
	for (index_1 = 0; index_1 < row; index_1++)
	{
		cout << "Enter the length of the string" << endl;
		cin >> column;
		array[index_1] = new char[column];
		cout << "Enter the string" << endl;
		cin >> array[index_1];
	}
	cout << "Enter the length of the string to be found" << endl;
	cin >> length;
	key = new char[length];
	cout << "Enter the string to be found" << endl;
	cin >> key;
	flag = linear_search(array, row, key);
	if (flag == 1)
		cout << "Element is found" << endl;
	if (flag == 0)
		cout << "Element is not found" << endl;
	system("pause");
	return 0;
}