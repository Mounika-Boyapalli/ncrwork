#include<iostream>
using namespace std;
//int Add(int temp_var1, int temp_var2)
//{
//	return (temp_var1 + temp_var2);
//}
//int Mul(int temp_var1, int temp_var2)
//{
//	return (temp_var1 * temp_var2);
//}
//int Operate(int temp_var1, int temp_var2, int(*f)(int, int))
//{
//	return (*f)(temp_var1, temp_var2);
//}

class Operate
{
public: Operate()  { }
		virtual int operator()(int, int);
};
class Add :public Operate
{
public: Add() { }
		virtual int operator()(int temp_var1, int temp_var2)
		{
			return (temp_var1 + temp_var2);
		}
};
class Mul : public Operate
{
public: Mul() { }
		virtual int operator()(int temp_var1, int temp_var2)
		{
			return (temp_var1 * temp_var2);
		}
};
int operate_func(int x, int y, Operate * obj)
{
	return (*obj)(x, y);
}
int main()
{
	Operate* obj1 = new Add();
	cout << "Result of Addition is " << Operate(20, 10, obj1) << endl;
	cout << "Result of Multiplication is " << Operate(20, 10, Mul) << endl;
	/*cout << "Result of Addition is " << Operate(20, 10, Add) << endl;
	cout << "Result of Multiplication is " << Operate(20, 10, Mul) << endl;*/
	system("pause");
	return 0;
}