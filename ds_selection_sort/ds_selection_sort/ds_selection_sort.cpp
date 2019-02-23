#include<iostream>
using namespace std;
void selection_sort(int[], int);
int main()
{
	int *array;
	int length, k;
	cout << "Enter the length of the array" << endl;
	cin >> length;
	array = new int[length];
	cout << "Enter the elements to be sorted" << endl;
	for (k = 0; k < length; k++)
		cin >> array[k];
	selection_sort(array, length);
	delete array;
	system("pause");
	return 0;
}
void selection_sort(int s[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[i] > s[j])
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
	cout << endl << "The sorted array is: " << endl;
	for (i = 0; i < n; i++)
		cout << " " << s[i];
}