#include<iostream>
using namespace std;
int* merge_sort(int[],int, int);
void merge(int[],int, int, int);
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
	array = merge_sort(array,0,length - 1);
	cout << "The sorted array is: " << endl;
	for (k = 0; k < length; k++)
		cout << " " << array[k];
	delete array;
	system("pause");
	return 0;
}
int* merge_sort(int a[],int low, int high)
{
	if (low < high)
	{
		int mid;
		mid = (low + high) / 2;
		merge_sort(a,low, mid);
		merge_sort(a,mid + 1, high);
		merge(a,low, mid, high);
	}
	return a;
}
void merge(int a[],int l1s, int l1e, int l2e)
{
	int i, j, k;
	int l2s = l1e + 1;
	int *l3;
	l3 = new int[l2e - l1s + 1];
	i = l1s;
	j = l2s;
	k = 0;
	while (i <= l1e && j <= l2e)
	{
		if (a[i] > a[j])
			l3[k++] = a[j++];
		else
			l3[k++] = a[i++];
	}
	while (i <= l1e)
		l3[k++] = a[i++];
	while (j <= l2e)
		l3[k++] = a[j++];
	while (l2e >= l1s)
		a[l2e--] = l3[--k];
	delete l3;
}