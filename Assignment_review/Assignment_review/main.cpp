#include<iostream>
using namespace std;
//defining a stack structure
struct __stack__
{
	int top;
	int *s;
	int size;
};
//defining stack class
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
//constructor
_stack_::_stack_()
{
	sta.top = -1;
	sta.s = NULL;
	sta.size = 0;
}
//to allocate memory for the stack
void _stack_::getsize(int n)
{
	sta.size = n;
	sta.s = new int[n];
}
//to check whether the stack is empty or not
bool _stack_::IsEmpty()
{
	return (sta.top == -1);
}
//to check whether stack is full or not
bool _stack_::IsFull()
{
	return (sta.top == (sta.size - 1));
}
//to insert elements into the stack
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
//to delete elements from the stack
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
//to know the value of the top most element
int _stack_::peek()
{
	int x = -999;
	if (!IsEmpty())
		x = sta.s[sta.top];
	else
		cout << "Stack is empty";
	return x;
}
//destructor
_stack_::~_stack_()
{
	delete sta.s;
	cout << "Deleted" << endl;
}
//to convert char into int for operations
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
	//two stacks are used. One for operands and the other for operators
	_stack_ operand, symbol;
	char *expression = NULL;
	int length = 0, index = 0, temp_var = 0, temp_variable = 0, flag_1 = 1;
    int variable1 = 0, variable2 = 0;
	cout << "Enter the length of the expression to be evaluated" << endl;
	cin >> length;
	//memory for operand stack is allocated
	operand.getsize(length);
	//memory for operator stack is allocated
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
			//if operator stack is empty, push the operator
			if (symbol.IsEmpty())
			{
				symbol.push(convert(expression[index]));
				continue;
			}
			else
			{
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
					case 5: result = mul(variable2, variable1);
							break;
					case 4: result = divi(variable2, variable1);
							break;
					case 3: result = add(variable2, variable1);
							break;
					case 2: result = sub(variable2, variable1);
							break;
					}
					symbol.push(convert(expression[index]));
					if (result == -999)
					{
						flag_1 = 0;
						return 0;
					}
					operand.push(result);
				}
			}
		}
		//operands have to be pushed onto the stack unconditionally
		else if ('0' <= expression[index] <= '9')
		{
			/*while (expression[index + 1] != '\0' && (expression[index + 1] != '+' || expression[index + 1] != '-' || expression[index + 1] != '*' || expression[index + 1] != '/'))
			{
				temp_variable = 10 * convert(expression[index]) + convert(expression[index + 1]);
				flag = 1;
			}
			if (flag == 1)
			{
				operand.push(temp_variable);
			}
			else if(flag == 0)*/
				operand.push(convert(expression[index]));
		}
	}
	//all the left out data in the stacks is poped out and operated upon
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
	//cout << flag_1 << endl;
	if (flag_1 == 0)
		cout << "Divide By Zero Error Occurred" << endl;
	else 
		cout << "Answer is " << operand.pop() << endl;

	symbol.~_stack_();
	operand.~_stack_();
	system("pause");
	return 0;
}