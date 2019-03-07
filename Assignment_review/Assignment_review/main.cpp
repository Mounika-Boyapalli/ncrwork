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
int convert(char character)
{
	switch (character)
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
int result=-1;
int main()
{
	_stack_ operand, symbol;
	char *expression = NULL;
	int length = 0, index = 0, temp_var = 0;
    int variable1 = 0, variable2 = 0;
	cout << "Enter the length of the expression to be evaluated" << endl;
	cin >> length;
	operand.getsize(length);
	symbol.getsize(length);
	expression = new char[length];
	cout << "Enter the expression to be evaluated" << endl;
	cin >> expression;
	for (index = 0; index < length; index++)
	{
		if (expression[index] == '(' || expression[index] == '[' || expression[index] == '{' || expression[index] == ')' || expression[index] == ']' || expression[index] == '}')
		{
			cout << "Brackets are invalid inputs" << endl;
			system("pause");
			return -1;
		}
		if (expression[index] == '+' || expression[index] == '-' || expression[index] == '*' || expression[index] == '/')
		{
			if (expression[index + 1] == '-')
			{
				cout << "Negative integers are not applicable" << endl;
				system("pause");
				return -1;
			}
			if (symbol.IsEmpty())
			{
				symbol.push(convert(expression[index]));
				continue;
			}
			if (convert(expression[index]) > symbol.peek())
			{
				symbol.push(convert(expression[index]));
			}
			else
			{
				variable1 = operand.pop();
				variable2 = operand.pop();
				switch (symbol.pop())
				{
				case 5:  result = mul(variable2, variable1);
					     break;
				case 4:  result = divi(variable2 , variable1);
					     break;
				case 3:  result = add(variable2, variable1);
					     break;
				case 2:  result = sub(variable2, variable1);
					     break;
				}
				symbol.push(convert(expression[index]));
				operand.push(result);
			}
		}
		else if ('0' <= expression[index] <= '9')
		{
			/*if ('0' <= expression[index+1] <= '9' )
			{
				operand.push((10 * convert(expression[index])) + convert(expression[++index]));
			}
			else*/
				operand.push(convert(expression[index]));
		}
	}
	while (!symbol.IsEmpty())
	{
		variable1 = operand.pop();
		variable2 = operand.pop();
		switch (symbol.pop())
		{
		case 5:  result = mul(variable2, variable1);
			     break;
		case 4:  result = divi(variable2, variable1);
			     break;
		case 3:  result = add(variable2, variable1);
			     break;
		case 2:  result = sub(variable2, variable1);
			     break;
		}
		operand.push(result);
	}
	cout << "Answer is " << operand.pop() << endl;
	symbol.~_stack_();
	operand.~_stack_();
	system("pause");
	return 0;
}