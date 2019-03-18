#include<iostream>
using namespace std;
class A
{
	int private_a;
public: int public_a;
		A()
		{
			private_a = public_a = 0;
		}
		A(int i, int j)
		{
			private_a = i;
			public_a = j;
		}
		void print_A()
		{
			cout << "Private_a is " << private_a << endl << "Public_a is " << public_a << endl;
		}
};
class B : public A
{
	int private_b;
public: int public_b;
		B()
		{
			private_b = public_b = 0;
		}
		B(int i, int j)
		{
			private_b = i;
			public_b = j;
		}
		void print_B()
		{
			cout << "Private_b is " << private_b << endl << "Public_b is " << public_b << endl;
		}
};
int main()
{
	A a_obj(2,3);
	B b_obj;
	cout << endl;
	//cout << "Private_a through b_obj " << b_obj.private_a << endl;
	//cout << "Private_b through b_obj " << b_obj.private_b << endl;
	cout << "Public_a through b_obj " << b_obj.public_a << endl;
	cout << "Public_b through b_obj " << b_obj.public_b << endl;
	cout << endl;
	b_obj.print_A();
	cout << endl;
	b_obj.print_B();
	cout << endl;
	system("pause");
	return 0;
}