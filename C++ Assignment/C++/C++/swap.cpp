#include <iostream>
using namespace std;
class swapc
{
	int a;
	int b;
public:  void get_swap(int x, int y)
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
			 cout << "Final values are "<<k.a<<endl<<k.b<<endl;
			
		 }
		 void swap_ref(swapc &k)
		 {
			 k.a = k.a + k.b;
			 k.b = k.a - k.b;
			 k.a = k.a - k.b;
		 }
		 void print_swap()
		 {
			 cout << a << endl << b << endl;
		 }
};
int main()
{
	int n;
	swapc c,c1;
	c.get_swap();
	cout << "1.Call by value"<<endl;
	cout << "2. Call by reference" << endl;
	cout << "Enter your choice";
	cin >> n;
	cout << "Initial values are ";
	c.print_swap();
	switch (n)
	{
	case 1: c1.swap_value(c);
		    
		    break;
	case 2: c1.swap_ref(c);
		    cout << "Final values are ";
		    c.print_swap();
		    break;
	default: cout << "Invalid Option";
		     break;
	}
	system("pause");
	return 0;
}