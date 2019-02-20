#include<iostream>
using namespace std;
void bubble_sort(int[], int);
int main()
{
	int *a;
	int l, i, j;
	cout << "Enter the length of the array" << endl;
	cin >> l;
	a = new int[l];
	cout << "Enter the elements to be sorted" << endl;
	for (i = 0; i < l; i++)
	{
		cin >> a[i];
	}
	bubble_sort(a, l);
	system("pause");
	return 0;
}

void bubble_sort(int s[], int n)
{
	int k, j, temp, flag=0;
	for (j = 0; j < n - 1; j++)
	{
		flag = 0;
		for (k = 0; k < n - 1 - j; k++)
		{
			if (s[k] > s[k + 1])
			{
				temp = s[k];
				s[k] = s[k+1];
				s[k+1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	cout << endl << "Sorted Array is: " << endl;
	for (j = 0; j < n; j++)
		cout << " " << s[j];
}
