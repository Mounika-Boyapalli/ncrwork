#include <iostream>
using namespace std;
class mul
{
	int m;
	int n;
public: mul (int x)
        {
			m = x;
			n = x;
	    }
		void get_mat(mul o)
		{
			int i;
		}
};

int main()
{
	int a,i,j;
	cout << "Enter the number of rows and columns";
	cin >> a ;
	mul m1(a), m2(a);
	int **ip;
	ip = new int*[a];
	for (i = 0; i < a; i++)
	{
		ip[i] = new int[a];
	}
	cout << "Enter the elements";
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{

		}
	}
	return 0;
}