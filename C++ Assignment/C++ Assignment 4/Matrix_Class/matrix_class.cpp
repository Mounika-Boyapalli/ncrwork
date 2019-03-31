#include <iostream>
using namespace std;
class __matrix__
{
	int **matrix;
	int row;
	int column;
public: __matrix__();
		__matrix__(int **, int, int);
		__matrix__(const __matrix__ &);
		void getSize();
		~__matrix__();
		__matrix__ operator+(const __matrix__ m)
		{
			__matrix__ temp_matrix;
			if (row == m.row && column == m.column)
			{
				int i, j;
				temp_matrix.row = row;
				temp_matrix.column = column;
				temp_matrix.matrix = new int*[temp_matrix.row];
				for (i = 0; i < row; i++)
				{
					temp_matrix.matrix[i] = new int[temp_matrix.column];
					for (j = 0; j < column; j++)
					{
						temp_matrix.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
					}
				}
				return temp_matrix;
			}
			else
			{
				cout << "Order Mismatch!" << endl;
				return temp_matrix;
			}
		}
		__matrix__ operator=(__matrix__ m)
		{
			int i, j;
			__matrix__ temp_matrix;
			temp_matrix.row = m.row;
			temp_matrix.column = m.column;
			if (temp_matrix.matrix == NULL)
			{
				temp_matrix.matrix = new int*[temp_matrix.row];
				for (i = 0; i < temp_matrix.row; i++)
				{
					temp_matrix.matrix[i] = new int[temp_matrix.column];
				}
			}
			temp_matrix.matrix = m.matrix;
			return temp_matrix;
		}
		friend istream& operator>>(istream& , __matrix__ &);
		friend ostream& operator<<(ostream& , __matrix__ );
};
__matrix__::__matrix__()
{
	matrix = NULL;
	row = 0;
	column = 0;
}
__matrix__::__matrix__(int **mat, int r, int c)
{
	int i, j;
	row = r;
	column = c;
	matrix = new int*[row];
	for (i = 0; i < row; i++)
	{
		matrix[i] = new int[column];
		for (j = 0; j < column; j++)
		{
			matrix[i][j] = mat[i][j];
		}
	}
}
__matrix__::__matrix__(const __matrix__ &m)
{
	int i, j;
	row = m.row;
	column = m.column;
	if (matrix == NULL)
	{
		matrix = new int*[row];
		for (i = 0; i < row; i++)
			matrix[i] = new int[column];
	}
	/*else
		delete matrix;*/
	matrix = m.matrix;
}
void __matrix__::getSize()
{
	cout << "Enter the order of the matrix" << endl;
	cin >> row >> column;
}
__matrix__::~__matrix__()
{
	int i;
	for (i = 0; i < row; i++)
	{
		delete matrix[i];
	}
	delete matrix;
}
istream& operator>>(istream& cin, __matrix__ &m)
{
	int i, j;
	m.matrix = new int*[m.row];
	for (i = 0; i < m.row; i++)
	{
		m.matrix[i] = new int[m.column];
		for (j = 0; j < m.column; j++)
		{
			cin >> m.matrix[i][j];
		}
	}
	return cin;
}
ostream& operator<<(ostream& cout, __matrix__ m)
{
	int i, j;
	for (i = 0; i < m.row; i++)
	{
		for (j = 0; j < m.column; j++)
		{
			cout << m.matrix[i][j];
		}
		cout << endl;
	}
	return cout;
}



int main()
{
	__matrix__ m1, m2, m3, m4;
	m1.getSize();
	cout << "Enter the elements" << endl;
	cin >> m1;
	m2.getSize();
	cout << "Enter the elements" << endl;
	cin >> m2;
	/*__matrix__ m2(m1);
	cout << "Copied matrix is" << endl;
	cout << m2 << endl;*/
	m3 = (m1 + m2);
	//m4 = m1;
	cout << "Equal to operation" << endl;
	cout << m4 << endl;
	system("pause");
	return 0;
}