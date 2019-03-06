#include<iostream>
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
int convert(char g)
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
	case '*': return 5;
		      break;
	case '/': return 4;
		      break;
	case '+': return 3;
        	  break;
	case '-': return 2;
			  break;
	}
}
int add(int, int);
int sub(int, int);
int mul(int, int);
int divi(int, int);
int r=-1;
int main()
{
	_stack_ o, s;
	char *e = NULL;
	int length = 0, i, temp;
    int a, b;
	cout << "Enter the length of the expression to be evaluated" << endl;
	cin >> length;
	o.getsize(length);
	s.getsize(length);
	e = new char[length];
	cout << "Enter the expression to be evaluated" << endl;
	cin >> e;
	for (i = 0; i < length; i++)
	{
		if (e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/')
		{
			if (s.IsEmpty() == 1)
			{
				s.push(convert(e[i]));
			}
			if (convert(e[i]) > s.peek())
			{
				s.push(convert(e[i]));
			}
			else
			{
				a = o.pop();
				b = o.pop();
				switch (s.pop())
				{
				case '*':  r = mul(b, a);
					       break;
				case '/':  r = divi(b , a);
					       break;
				case '+':  r = add(b, a);
					       break;
				case '-':  r = sub(b, a);
					       break;
				}
				s.push(convert(e[i]));
				o.push(r);
			}
		}
		else if ('0' <= e[i] <= '9')
		{
			o.push(convert(e[i]));
		}
	}
	cout << "Answer is " << o.pop() << endl;
	system("pause");
	return 0;
}