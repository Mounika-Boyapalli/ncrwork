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
	
public: 
	    _stack_();
		
		void push(char);
		char pop();
		char peek();
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
		cout << "Stack is full"<<endl;
}
char _stack_::pop()
{
	int x = -999;
	if (!IsEmpty())
	{
		x = sta.s[sta.top];
		sta.top--;
	}
	else
		cout << "Stack is empty"<<endl;
	return x;
}
char _stack_::peek()
{
	int x = -999;
	if (!IsEmpty())
		x = sta.s[sta.top];
	else
		cout << "Stack is empty"<<endl;
	return x;
}

_stack_::~_stack_()
{
	delete sta.s;
}

/*class string2
{
public :
	char *sp;
	int len;
   string2 (const char *s)
   {
				len = strlen(s);
				sp = new char[len];
				strcpy_s(sp, len, s);
   }
};*/
int main()
{
	_stack_ s1;
	int len;
	char s2[15];
	cout << "Enter the string" << endl;
	cin >> s2;
	len = strlen(s2);
	int l,i,flag=0;
	char ch;
	cout << "Enter the size of stack";
	cin >> l;
	s1.getsize(l);
	for (i = 0; i < len; i++)
	{
		ch = s2[i];
		switch (ch)
		{
		case '(' : 
		case '[' :
		case '{' : s1.push(ch);
			       break;
		case ')' :
		case ']' :
		case '}': if (((ch == ')') && (s1.peek() == '(')) || ((ch == ']') && (s1.peek() == '[')) || ((ch == '}') && (s1.peek() == '{')))
				  {
						s1.pop();
						break;
				  }
				  else
				  {
					  flag = 1;
					  break;
				  }

        }
	}
	if ((s1.IsEmpty()) && flag != 1)
		cout << "Balanced" << endl;
	else
		cout << "Unbalanced"<<endl;
	cout << "flag value is " << flag << endl;
	system("pause");
	return 0;
}