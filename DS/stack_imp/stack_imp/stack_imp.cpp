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
    public : _stack_();
	         void push(int);
	         int pop();
			 int peek();
			 bool IsEmpty();
			 bool IsFull();
			 void display();
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
	return (sta.top == (sta.size-1));
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
void _stack_::display()
{
	int i;
	for (i = 0; i <= sta.top; i++)
	{
		cout << " " << sta.s[i] ;
	}
}
_stack_::~_stack_()
{
	delete sta.s;
}
int main()
{
	int a, m,n,siz,j;
	_stack_ s1;
	cout << "Enter the size of stack";
	cin >> siz;
	s1.getsize(siz);
	for (j = 0; j < 5; j++)
	{
		cout << "Choose an option" << endl << "1.Add an element" << endl;
		cout << "2.Delete an element" << endl << "3. Peek" << endl << "4. Display" << endl;
		cin >> a;
		switch (a)
		{
		case 1: cout << "Enter the element";
			cin >> m;
			s1.push(m);
			break;
		case 2: n = s1.pop();
			cout << n;
			break;
		case 3: n = s1.peek();
			cout << n;
			break;
		case 4: s1.display();
			break;
		default: cout << "Invalid option" << endl;
			break;
		}
		cout << endl << endl;
	}
	system("pause");
	return 0;
}