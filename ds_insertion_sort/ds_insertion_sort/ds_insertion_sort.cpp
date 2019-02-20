#include<iostream>
using namespace std;
void insertion_sort(int[], int);
int main()
{
	int *a;
	int l, k;
	cout << "Enter the length of the array" << endl;
	cin >> l;
	a = new int[l];
	cout << "Enter the elements to be sorted" << endl;
	for (k = 0; k < l; k++)
	{
		cin >> a[k];
	}
	insertion_sort(a, l);
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