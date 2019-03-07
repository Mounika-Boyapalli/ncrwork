#include <iostream>
using namespace std;
struct __stack__
{
	int top;
	char *s;
	int size;
};
class _stack_
{
	struct __stack__ sta;
public: _stack_();
		void push(char);
		char pop();
		char peek();
		bool IsEmpty();
		bool IsFull();
		~_stack_();
		void getsize(int);
		int priority(char);
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
	sta.s = new char[n];
}
bool _stack_::IsEmpty()
{
	return (sta.top == -1);
}
bool _stack_::IsFull()
{
	return (sta.top == (sta.size - 1));
}
void _stack_::push(char ele)
{
	if (!IsFull())
	{
		sta.top++;
		sta.s[sta.top] = ele;
	}
	else
		cout << "Stack is full";
}
char _stack_::pop()
{
	char x = '\0';
	if (!IsEmpty())
	{
		x = sta.s[sta.top];
		sta.top--;
	}
	else
		cout << "Stack is empty";
	return x;
}
char _stack_::peek()
{
	char x = '\0';
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
int _stack_::priority(char c)
{
	switch (c)
	{
	case '*':
	case '/': return 5;
		break;
	case '-':
	case '+': return 4;
		break;
	case '[':
	case ']':
	case '(':
	case ')': return 3;
		break;
	}
}

int main()
{
	int siz, l, i, j = 0;
	cout << "Enter the size of the stack" << endl;
	cin >> siz;
	char *s;
	char ch, temp, str[15];
	cout << "Enter the length of the string" << endl;
	cin >> l;
	s = new char[l];
	cout << "Enter the expression" << endl;
	cin >> s;
	_stack_ s1;
	s1.getsize(siz);
	for (i = 0; s[i]; i++)
	{
		ch = s[i];
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			str[j] = ch;
			j++;
		}
		else
		{
			if (s1.IsEmpty())
				s1.push(ch);
			else if (ch != '(' && ch != ')' && ch != '[' && ch != ']')
			{
				if (s1.priority(ch) > s1.priority(s1.peek()))
					s1.push(ch);
				else
				{
					temp = s1.pop();
					if (temp != '(' && temp != '[')
					{
						str[j] = temp;
						j++;
					}
					s1.push(ch);
				}
			}
			else if (ch == '(' || ch == '[')
				s1.push(ch);
			else
			{
				switch (ch)
				{
				case ')': while (s1.peek() != '(')
				{
					temp = s1.pop();
					str[j] = temp;
					j++;
				}
						  temp = s1.pop();
						  break;
				case ']': while (s1.peek() != '[')
				{
					temp = s1.pop();
					str[j] = temp;
					j++;
				}
						  temp = s1.pop();
						  break;
				}
			}
		}

	}
	while (!s1.IsEmpty())
	{
		temp = s1.pop();
		if (temp != '(')
		{
			str[j] = temp;
			j++;
		}
	}
	str[j] = '\0';
	cout << "Postfix expression is " << str << endl;
	system("pause");
	return 0;
}