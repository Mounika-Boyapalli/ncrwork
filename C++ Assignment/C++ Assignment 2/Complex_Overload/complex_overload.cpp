#include<iostream>
using namespace std;
class complex
{
	float real;
	float img;
public: complex(float r, float i)
		{
			real = r;
			img = i;
		}
		complex()
		{
			img = 0;
			real = 0;
		}
		complex(float r)
		{
			real = r;
			img = r;
		}
		complex operator+ (complex c)
		{
			complex temp;
			temp.real = real + c.real;
			temp.img = img + c.img;
			return (temp);
		}
		complex operator- (complex c)
		{
			complex temp;
			temp.real = real - c.real;
			temp.img = img - c.img;
			return (temp);
		}
		complex operator- ()
		{
			complex temp;
			temp.real = -real;
			temp.img = -img;
			return temp;
		}
		complex operator++ ()
		{
			complex temp;
			temp.real = ++real;
			temp.img = ++img;
			return temp;
		}
		complex operator++ (int x)
		{
			complex temp;
			temp.real = real++;
			temp.img = img++;
			return temp;
		}
		complex operator, (complex c)
		{
			return c;
		}
		complex *operator-> ()
		{
			return this;
		}
		friend ostream& operator<< (ostream& cout, complex c);
		friend istream& operator>> (istream& cin, complex &c);
};
ostream& operator<< (ostream& cout, complex c)
{
	cout << "Real = " << c.real << endl;
	cout << "Img = " << c.img << endl;
	return (cout);
}
istream& operator>> (istream& cin, complex &c)
{
	cout << "Enter the real part of the complex number" << endl;
	cin >> c.real;
	cout << "Enter the imaginary part of the complex number" << endl;
	cin >> c.img;
	return (cin);
}

int main()
{
	complex c_num1, c_num2, c_output;
	cout << "Enter first complex number" << endl;
	cin >> c_num1;
	cout << "Enter second complex number" << endl;
	cin >> c_num2;
	c_output = c_num1 + c_num2;
	cout << "Sum of the two complex numbers is " << endl << c_output << endl;
	c_output = c_num1 - c_num2;
	cout << "Difference of the two complex numbers is " << endl << c_output << endl;
	c_output = c_num1 + (-c_num2);
	cout << "The complex number with unary operator is " << endl << c_output << endl;
	c_output = c_num1++;
	cout << "Post increment operation on first complex number is " << endl << c_output << endl;
	c_output = ++c_num1;
	cout << "Pre increment operation on first complex number is " << endl << c_output << endl;
	c_output = c_num1,c_num2;
	//c_output = (c_num1, c_num2);
	cout << "Comma operator output is " << endl << c_output << endl;
	system("pause");
	return 0;
}