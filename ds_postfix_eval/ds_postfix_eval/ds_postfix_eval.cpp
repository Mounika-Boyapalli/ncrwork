#include <iostream>
using namespace std;
struct __stack__
{
	int top;
	int *s;
	int size;
};
class _stack_
{
	struct __stack__ sta;
public: _stack_();
		void push(int);
		int pop();
		int peek();
		bool IsEmpty();
		bool IsFull();
		~_stack_();
		void getsize(int);
};

_stack_::_stack_()
{
	sta.top = -1;
	sta.s = NULL;
	sta.size = 0;
}
void _stack_::getsize(int n)
{
	sta.size = n;
	sta.s = new int[n];
}
bool _stack_::IsEmpty()
{
	return (sta.top == -1);
}
bool _stack_::IsFull()
{
	return (sta.top == (sta.size - 1));
}
void _stack_::push(int ele)
{
	if (!IsFull())
	{
		sta.top++;
		sta.s[sta.top] = ele;
	}
	else
		cout << "Stack is full";
}
int _stack_::pop()
{
	int x = -999;
	if (!IsEmpty())
	{
		x = sta.s[sta.top];
		sta.top--;
	}
	else
		cout << "Stack is empty";
	return x;
}
int _stack_::peek()
{
	int x = -999;
	if (!IsEmpty())
		x = sta.s[sta.top];
	else
		cout << "Stack is empty";
	return x;
}
_stack_::~_stack_()
{
	delete sta.s;
}

int main()
{
	_stack_ s1;
	int siz, l, i;
	char ch, *str;
	cout << "Enter the size of the stack" << endl;
	cin >> siz;
	s1.getsize(siz);
	cout << "Enter the length of the expression" << endl;
	cin >> l;
	str = new char[l];
	cout << "Enter the expression" << endl;
	cin >> str;
	for (i = 0; str[i]; i++)
	{
		ch = (int)str[i];
		str[i] = ch;
	}

	system("pause");
	return 0;
}