#include<iostream>
using namespace std;
void selection_sort(int[], int);
int main()
{
	int *a;
	int l, k;
	cout << "Enter the length of the array" << endl;
	cin >> l;
	a = new int[l];
	cout << "Enter the elements to be sorted" << endl;
	for (k = 0; k < l; k++)
		cin >> a[k];
	selection_sort(a, l);
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