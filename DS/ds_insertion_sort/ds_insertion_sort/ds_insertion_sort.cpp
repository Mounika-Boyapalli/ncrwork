#include<iostream>
using namespace std;
void insertion_sort(int[], int);
int main()
{
	int *array;
	int length, k;
	cout << "Enter the length of the array" << endl;
	cin >> length;
	array = new int[length];
	cout << "Enter the elements to be sorted" << endl;
	for (k = 0; k < length; k++)
	{
		cin >> array[k];
	}
	insertion_sort(array, length);
	delete array;
	system("pause");
	return 0;
}
void insertion_sort(int s[], int n)
{
	int i, j, temp;
	for (i = 1; i <= n - 1; i++)
	{
		j = i - 1;
		temp = s[i];
		while (j >= 0 && s[j] > temp)
		{
			s[j + 1] = s[j];
			j--;
		}
		s[j + 1] = temp;
	}
	cout << endl << "The sorted array is: " << endl;
	for (i = 0; i < n; i++)
		cout << " " << s[i];
}