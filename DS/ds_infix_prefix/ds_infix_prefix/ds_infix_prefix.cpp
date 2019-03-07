#include<iostream>
using namespace std;
struct stack__
{
	int top;
	char *s;
	int size;
};
class stack {
	struct stack__ sta;
public:
	stack();
	void getsize(int);
	void push(char);
	char pop();
	char peek();
	bool IsEmpty();
	bool IsFull();
	void display();
	int priority(char);
	void eval(char *name);
	~stack();
};
stack::stack()
{
	sta.top = -1;
	sta.size = 0;
	strcpy(sta.s, "");
}
void stack::getsize(int n)
{
	sta.size = n;
	sta.s = new char[n];
}
bool stack::IsEmpty()
{
	return(sta.top == -1);
}
bool stack::IsFull()
{
	return(sta.top == (sta.size - 1));
}

void stack::push(char ele)
{
	if (!IsFull())
		sta.s[++sta.top] = ele;
	else
		cout << "Stack overflow" << endl;
}
char stack::pop()
{
	char x;
	if (!IsEmpty())

		x = sta.s[sta.top--];

	else
		cout << "Stack underflow" << endl;
	return x;
}
char stack::peek()
{
	char x;
	if (!IsEmpty())

		x = sta.s[sta.top];
	else
		cout << "Stack underflow" << endl;
	return x;
}
void stack::display()
{
	for (int i = 0; i <= sta.top; i++)
		cout << sta.s[i];
}
int stack::priority(char ch)
{
	switch (ch)
	{
	case '*':
	case '/':return 5;
		     break;
	case '+':
	case '-':return 4;
		     break;
	case']':
	case '}':
	case ')':return 2;
		     break;
	}

}
void stack::eval(char *name)
{
	char str[30];
	int j = 0;
	char temp, x, y;
	int l = strlen(name);
	for (int i = l - 1; i >= 0; i--)
	{
		char ch;
		ch = name[i];

		if (ch >= 'a'&&ch <= 'z')
		{

			str[j] = ch;
			j++;
		}
		else if (IsEmpty())
			push(ch);

		else if (ch == '*' || ch == '/' || ch == '+' || ch == ')' || ch == '}' || ch == '-' || ch == ']')
		{
			if (ch == ')' || ch == '}' || ch == ']')
				push(ch);
			else if (priority(ch) > priority(peek()))
				push(ch);

			else if (priority(ch) <= priority(peek()))
			{
				temp = pop();
				str[j] = temp;
				j++;
				push(ch);
			}
		}
		if (ch == '(') {
			while (peek() != ')')
			{
				temp = pop();
				str[j] = temp;
				j++;
			}
			if (peek() == ')') 
				x = pop();
		}

		if (ch == '{')
		{
			while (peek() != '}')
			{
				temp = pop();
				str[j] = temp;
				j++;
			}
			if (peek() == '}') 
				y = pop();
		}
		if (ch == '[')
		{
			while (peek() != ']')
			{
				temp = pop();
				str[j] = temp;
				j++;
			}
			if (peek() == ']') 
				y = pop();
		}
	}
    while (sta.top >= 0)
	{
		temp = pop();
		str[j] = temp;
		j++;
	}
	strrev(str);
	cout << "Prefix:" << str;
}
stack::~stack()
{
	delete sta.s;
}
int main()
{
	int  siz;
	stack s1;
    char exp[20];
	cout << "Enter the infix expression: " << endl;
	cin >> exp;
	cout << "Enter size" << endl;
	cin >> siz;
	s1.getsize(siz);
	s1.eval(exp);
	system("pause");
	return 0;
}