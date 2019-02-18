#include<iostream>
using namespace std;
class matrix
{
	int a[3][3];

public:
	void get_data()
	{

		int i, j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				cin >> a[i][j];

		}

	}
	friend matrix mult(matrix, matrix);
	void display()
	{
		int i, j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				cout << a[i][j] << " ";
			cout << endl;

		}
	}
};
matrix mult(matrix m1, matrix m2)
{
	matrix m;
	int k, i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			m.a[i][j] = 0;
		}

	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				m.a[i][j] = m.a[i][j] + m1.a[i][k] + m2.a[k][i];

			}
		}
	}
	return m;

}
int main()
{
	matrix m1, m2, m3;
	m1.get_data();
	m2.get_data();
	m3 = mult(m1, m2);
	m3.display();
	system("pause");
	return 0;
}