#include<iostream>
using namespace std;
int partition(int array[], int low, int  high)
{
	int pivot = array[low];
	int i, j, temp;
	i = low + 1;
	j = high;
	while (low < high)
	{


		while (i <= high && array[i] < pivot)
			i++;
		while (j >= low && array[j] > pivot)
			j--;
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		else break;
	}

	temp = array[j];
	array[j] = array[low];
	array[low] = temp;
	return j;
}
void quick_sort(int array[], int low, int high)
{
	int j;
	if (low < high)
	{
		j = partition(array, low, high);
		quick_sort(array, low, j);
		quick_sort(array, j + 1, high);
	}
}
int main()
{
	int *array, i, j, length, temp;
	cout << "Enter the length of array " << endl;
	cin >> length;
	array = new int[length];
	cout << "Enter the elements to be sorted " << endl;
	for (i = 0; i < length; i++)
		cin >> array[i];
	quick_sort(array, 0, length - 1);
	cout << "Sorted array is: " << endl;
	for (i = 0; i < length; i++)
		cout << " " << array[i] ;
	delete array;
	system("pause");
	return 0;
}