#include<iostream>
using namespace std;
int main()
{
	int *array;
	int length, i, key, found = 0;
	cout << "Enter the length of the array" << endl;
	cin >> length;
	array = new int[length];
	cout << "Enter the elements of the array" << endl;
	for (i = 0; i < length; i++)
		cin >> array[i];
	cout << "Enter the element to be searched" << endl;
	cin >> key;
	for (i = 0; i < length; i++)
	{
		if (array[i] == key)
		{
			cout << "Element found at " << i + 1 << "th position" << endl;
			found = 1;
		}
	}
	if (found == 0)
		cout << "Element not found in the array" << endl;
	delete array;
	system("pause");
	return 0;
}