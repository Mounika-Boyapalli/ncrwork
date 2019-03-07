#include<iostream>
using namespace std;
void heap_sort(int[], int);
void build_heap(int[], int);
int main()
{
	int *array;
	int length, i;
	cout << "Enter the length of the array " << endl;
	cin >> length;
	array = new int[length];
	cout << "Enter the elements to be sorted " << endl;
	for (i = 0; i < length; i++)
		cin >> array[i];
	heap_sort(array, length);
	cout << "Sorted elements are: " << endl;
	for (i = 0; i < length; i++)
		cout << " " << array[i];
	delete array;
	system("pause");
	return 0;
}
void heap_sort(int a[], int n)
{
	int i, temp;
	for (i = n - 1; i >= 0; i--)
	{
		build_heap(a, i + 1);
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
	}
}
void build_heap(int a[], int n)
{
	int i, x, y, temp;
	for (i = 1; i < n; i++)
	{
		x = i;
		y = (x - 1) / 2;
		while (x > 0)
		{
			if (a[x] > a[y])
			{
				temp = a[x];
				a[x] = a[y];
				a[y] = temp;
			}
			else
				break;
			x = y;
			y = (x - 1) / 2;
		}
	}
}