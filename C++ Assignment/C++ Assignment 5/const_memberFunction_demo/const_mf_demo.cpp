#include <iostream>
using namespace std;
class MyClass
{
	mutable int private_a;
	int private_b;
public: MyClass()
		{
			private_a = 0;
			private_b = 0;
		}
		MyClass(int a, int b) 
		{
			private_a = a;
			private_b = b;
		}
		int getA() const
		{
			return private_a;
		}
		int getB() const
		{
			return private_b;
		}
		void setA(int a) const
		{
			private_a = a;
		}
};

int main()
{
	MyClass obj(2, 5);
	cout << "Values in MyClass are " << obj.getA() << endl;
	obj.setA(8);
	cout << "Values in MyClass are " << obj.getA() << endl;
	system("pause");
	return 0;
}