#include<iostream>
using namespace std;
template <class T>
int linear_search(T a[], int n, T ele)
{
	int index = 0, flag = 0;
	for (index = 0; index < n; index++)
	{
		if (a[index] == ele)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()
{
	linear_search <char>;
	char *array, key = 0;
	int element = 0, length = 0, index = 0, flag = 0;
	cout << "Enter the length of the array" << endl;
	cin >> length;
	array = new char[length];
	cout << "Enter the elements in arrays" << endl;
	for (index = 0; index < length; index++)
	{
		cin >> array[index];
	}
	cout << "Enter the element to be found" << endl;
	cin >> key;
	flag = linear_search(array, length, key);
	if (flag == 1)
		cout << "Element is found" << endl;
	if (flag == 0)
		cout << "Element is not found" << endl;
	system("pause");
	return 0;
}