#include<iostream>
using namespace std;
#define SIZE 20
class complex
{
	float real;
	float img;
public: complex()
		{
			img = 0;
			real = 0;
		}
		complex(float r)
		{
			real = r;
			img = r;
		}
		void print_complex()
		{
			cout << "real = " << real << endl;
			cout << "imag = " << img << endl;
		}
		friend ostream& operator<<(ostream& cout, complex c);
		friend istream& operator>>(istream& cin, complex &c);
};
ostream& operator<<(ostream& cout, complex c)
{
	cout << "real = " << c.real << endl;
	cout << "imag = " << c.img << endl;
	return (cout);
}
istream& operator>>(istream& cin, complex &c)
{
	cout << "Enter the real part" << endl;
	cin >> c.real;
	cout << "Enter the imaginary part" << endl;
	cin >> c.img;
	return(cin);
}
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
	__stack__ <complex> complex_stack;
	complex complex_1;
	int choice = 0;
	while (1)
	{
		cout << "Choose an operation " << endl << "1.push" << endl << "2.pop" << endl << "3.peek" << endl << "4.display" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Enter the complex number " << endl;
			cin >> complex_1;
			complex_stack.push(complex_1);
			break;
		case 2: complex_1 = complex_stack.pop();
			cout << complex_1;
			break;
		case 3: complex_1 = complex_stack.peek();
			cout << complex_1;
			break;
		case 4: complex_stack.display();
			break;
		default: cout << "Invalid Option" << endl;
		}
	}
	system("pause");
	return 0;
}