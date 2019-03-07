#include<iostream>
using namespace std;
int main()
{
	int *array;
	int length, i, key, high, low, mid, found = 0;
	cout << "Enter the length of the array " << endl;
	cin >> length;
	array = new int[length];
	cout << "Enter the sorted elements " << endl;
	for (i = 0; i < length; i++)
		cin >> array[i];
	cout << "Enter the element to be searched " << endl;
	cin >> key;
	low = 0;
	high = length - 1;
	mid = (low + high) / 2;
	while (low <= high)
	{
		if (array[mid] == key)
		{
			cout << "Element is found at " << mid + 1 << "th position " << endl;
			found = 1;
			break;
		}
		else if (array[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (found == 0)
		cout << "Element is not found in the array " << endl;
	delete array;
	system("pause");
	return 0;
}