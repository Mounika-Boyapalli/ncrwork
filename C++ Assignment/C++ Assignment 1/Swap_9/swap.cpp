#include <iostream>
using namespace std;
class swapc
{
	int a;
	int b;
public: swapc()
		{
			a = b = 0;
		}
	    void get_swap(int x, int y)
		{
			a = x;
			b = y;
		}
		void get_swap()
		{
			cin >> a >> b;
		}
		void swap_value(swapc k)
		{
			k.a = k.a + k.b;
			k.b = k.a - k.b;
			k.a = k.a - k.b;
			cout << "Final values are " << k.a << " " << k.b << endl;
		}
		void swap_ref(swapc &k)
		{
			k.a = k.a + k.b;
			k.b = k.a - k.b;
			k.a = k.a - k.b;
		}
		void print_swap()
		{
			cout << a << " " << b << endl;
		}
};
int main()
{
	int choice = 0;
	swapc values_before_swap, values_after_swap;
	cout << "Enter two variables" << endl;
	values_before_swap.get_swap();
	cout << "1.Call by value" << endl;
	cout << "2. Call by reference" << endl;
	cout << "Enter your choice";
	cin >> choice;
	cout << "Initial values are ";
	values_before_swap.print_swap();
	switch (choice)
	{
		case 1: values_after_swap.swap_value(values_before_swap);
				break;
		case 2: values_before_swap.swap_ref(values_before_swap);
				cout << "Final values are ";
				values_before_swap.print_swap();
				break;
		default: cout << "Invalid Option";
				 break;
	}
	system("pause");
	return 0;
}