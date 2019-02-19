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
		int convert(char);
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
int _stack_::convert(char g)
{
	switch (g)
	{
	case '0': return 0;
		break;
	case '1': return 1;
		break;
	case '2': return 2;
		break;
	case '3': return 3;
		break;
	case '4': return 4;
		break;
	case '5': return 5;
		break;
	case '6': return 6;
		break;
	case '7': return 7;
		break;
	case '8': return 8;
		break;
	case '9': return 9;
		break;
	}
}
int main()
{
	_stack_ s1;
	int l, siz, i, v, result, h;
	char ch, *sp;
	cout << "Enter the size of stack" << endl;
	cin >> siz;
	cout << "Enter the length of the expression" << endl;
	cin >> l;
	sp = new char[l];
	cout << "Enter the expression";
	cin >> sp;
	s1.getsize(siz);
	for (i = 0; sp[i]; i++)
	{
		ch = sp[i];
		if (isdigit(ch))
		{
			v = s1.convert(ch);
			s1.push(v);
		}
		else
		{
			switch (ch)
			{
			case '+': h = s1.pop();
				result = s1.pop() + h;
				s1.push(result);
				break;
			case '-': h = s1.pop();
				result = s1.pop() - h;
				s1.push(result);
				break;
			case '*': h = s1.pop();
				result = s1.pop() * h;
				s1.push(result);
				break;
			case '/': h = s1.pop();
				result = s1.pop() / h;
				s1.push(result);
				break;
			}
		}
	}
	cout << "Result is " << s1.pop() << endl;
	system("pause");
	return 0;
}