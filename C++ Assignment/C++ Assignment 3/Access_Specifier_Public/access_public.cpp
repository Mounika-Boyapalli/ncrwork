#include<iostream>
using namespace std;
class A
{
	int private_a;
protected: int protected_a;
		   void print_P_A()
		   {
			   cout << "Private_a is " << private_a << endl << "Protected_a is " << protected_a << endl << "Public_a is " << public_a << endl;
		   }
public: int public_a;
		A()
		{
			private_a = public_a = protected_a = 0;
		}
		A(int i, int j, int k)
		{
			private_a = i;
			protected_a = j;
			public_a = k;
		}
		void print_A()
		{
			cout << "Private_a is " << private_a << endl << "Protected_a is " << protected_a << endl << "Public_a is " << public_a << endl;
		}
};
class B : public A
{
	int private_b;
protected: int protected_b;
		   void print_P_B()
		   {
			   cout << "Private_b is " << private_b << endl << "Protected_b is " << protected_b << endl << "Public_b is " << public_b << endl;
		   }
public: int public_b;
		B()
		{
			private_b = public_b = protected_b = 0;
		}
		B(int i, int j, int k)
		{
			private_b = i;
			protected_b = j;
			public_b = k;
		}
		void print_B()
		{
			cout << "Private_b is " << private_b << endl << "Protected_b is " << protected_b << endl << "Public_b is " << public_b << endl;
		}
};
int main()
{
	A a_obj;
	B b_obj(2,3,4);
	cout << endl;
	cout << "Private_a through b_obj " << b_obj.private_a << endl;
	cout << "Private_b through b_obj " << b_obj.private_b << endl;
	cout << "Protected_a through b_obj " << b_obj.protected_a << endl;
	cout << "Protected_b through b_obj " << b_obj.protected_b << endl;
	cout << "Public_a through b_obj " << b_obj.public_a << endl;
	cout << "Public_b through b_obj " << b_obj.public_b << endl;
	cout << endl;
	b_obj.print_A();
	cout << endl;
	b_obj.print_P_A();
	cout << endl;
	b_obj.print_B();
	cout << endl;
	b_obj.print_P_B();
	cout << endl;
	system("pause");
	return 0;
}