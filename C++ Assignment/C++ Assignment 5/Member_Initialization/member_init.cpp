#include <iostream>
using namespace std;
class MyClass
{
	const int numA;
	const int numB;
public: MyClass(int temp_var1, int temp_var2):numA(temp_var1),numB(temp_var2) {  }
		int getA()		{ return numA; }
		int getB()		{ return numB; }
};
class MyClass_New
{
public: MyClass myclass_obj;
		MyClass_New(int x, int y):myclass_obj(x,y) { }
};
int main()
{
	MyClass_New obj(5, 10);
	//cout << "The value of numA is " << obj.getA() << endl;
	//cout << "The value of numB is " << obj.getB() << endl;
	system("pause");
	return 0;
}
