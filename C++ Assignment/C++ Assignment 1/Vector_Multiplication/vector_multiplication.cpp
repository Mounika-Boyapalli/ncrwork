#include<iostream>
using namespace std;
class matrix
{
	int a[3][3];

public: matrix()
		{
			int index_1 = 0, index_2 = 0;
			for (index_1 = 0; index_1 < 3; index_1++)
			{
				for (index_2 = 0; index_2 < 3; index_2++)
				{
					a[index_1][index_2] = 0;
				}
			}
		}
	    void get_data()
		{
			int index_1 = 0, index_2 = 0;
			for (index_1 = 0; index_1 < 3; index_1++)
			{
				for (index_2 = 0; index_2 < 3; index_2++)
					cin >> a[index_1][index_2];
			}
		}
		void display()
		{
			int index_1 = 0, index_2 = 0;
			for (index_1 = 0; index_1 < 3; index_1++)
			{
				for (index_2 = 0; index_2 < 3; index_2++)
					cout << a[index_1][index_2] << " ";
				cout << endl;
			}
		}
		friend matrix mult(matrix, matrix);
};
matrix mult(matrix m1, matrix m2)
{
	matrix m_product;
	int index_1 = 0, index_2 = 0, index_3 = 0;
	for (index_1 = 0; index_1 < 3; index_1++)
	{
		for (index_2 = 0; index_2 < 3; index_2++)
		{
			for (index_3 = 0; index_3 < 3; index_3++)
			{
				m_product.a[index_1][index_2] = m_product.a[index_1][index_2] + (m1.a[index_1][index_3] * m2.a[index_3][index_1]);
			}
		}
	}
	return m_product;
}
int main()
{
	matrix matrix_1, matrix_2, matrix_3;
	cout << "Enter first 3x3 matrix" << endl;
	matrix_1.get_data();
	cout << "Enter second 3x3 matrix" << endl;
	matrix_2.get_data();
	matrix_3 = mult(matrix_1, matrix_2);
	cout << "Product of the two 3x3 matrices is " << endl;
	matrix_1.display();
	system("pause");
	return 0;
}