#include<iostream>
using namespace std;
#define SIZE 20
template <class T>
class __stack__
{
	T stack[SIZE];
	int top;
public: __stack__()
		{
			top = -1;
		}
		void push(T element)
		{
			if (top == (SIZE - 1))
			{
				cout << "Stack Overflow" << endl;
			}
			else
			{
				stack[++top] = element;
			}
		}
		T pop()
		{
			if (top == -1)
			{
				cout << "Stack Underflow" << endl;
				return -1;
			}
			else
			{
				return(stack[top--]);
			}
		}
		T peek()
		{
			if (top == -1)
			{
				cout << "Stack Underflow" << endl;
				return -1;
			}
			else
			{
				return(stack[top]);
			}
		}
		void display()
		{
			int index = 0;
			for (index = 0; index <= top; index++)
			{
				cout << stack[index] << "  ";
			}
		}
};

int main()
{
	__stack__ <int> int_stack;
	__stack__ <float> float_stack;
	__stack__ <char> char_stack;
	int type_choice = 0, choice = 0;
	int value_int = 0;
	float value_float = 0, r = 0, i = 0;
	char value_char = '\0';
	while (1)
	{
		cout << "Select the type of stack to be used" << endl;
		cout << "1.Integer type" << endl << "2.Float type" << endl << "3.Char type" << endl << "4.Complex type" << endl;
		cin >> type_choice;
		switch (type_choice)
		{
			case 1: cout << "Select operation" << endl;
					cout << "1.push" << endl << "2.pop" << endl << "3.peek" << endl << "4.display()" << endl;
					cin >> choice;
					switch (choice)
					{
						case 1: cout << "Enter an element" << endl;
								cin >> value_int;
								int_stack.push(value_int);
								break;
						case 2: value_int = int_stack.pop();
								cout << value_int << endl;
								break;
						case 3: value_int = int_stack.peek();
								cout << value_int << endl;
								break;
						case 4: int_stack.display();
								break;
						default: cout << "Invalid Option" << endl;
					}
					break;
			case 2: cout << "Select operation" << endl;
					cout << "1.push" << endl << "2.pop" << endl << "3.peek" << endl << "4.display" << endl;
					cin >> choice;
					switch (choice)
					{
						case 1: cout << "Enter an element" << endl;
								cin >> value_float;
								float_stack.push(value_float);
								break;
						case 2: value_float = float_stack.pop();
								cout << value_float << endl;
								break;
						case 3: value_float = float_stack.peek();
								cout << value_float << endl;
								break;
						case 4: float_stack.display();
								break;
						default: cout << "Invalid Option" << endl;
					}
					break;
			case 3: cout << "Select operation" << endl;
					cout << "1.push" << endl << "2.pop" << endl << "3.peek" << endl << "4.display" << endl;
					cin >> choice;
					switch (choice)
					{
						case 1: cout << "Enter an element" << endl;
								cin >> value_char;
								char_stack.push(value_char);
								break;
						case 2: value_char = char_stack.pop();
								cout << value_char << endl;
								break;
						case 3: value_char = char_stack.peek();
								cout << value_char << endl;
								break;
						case 4: char_stack.display();
								break;
						default: cout << "Invalid Option" << endl;
					}
					break;
			default: cout << "Invalid Option" << endl;
		}
	}
	system("pause");
	return 0;
}