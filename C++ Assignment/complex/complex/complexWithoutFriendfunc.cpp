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
		void print_complex()
		{
			cout << "real = " << real << endl;
			cout << "imag = " << img << endl;
		}
		void addcomplex(complex c1, complex c2)
		{
			real = c1.real + c2.real;
			img = c1.img + c2.img;
		}
		void multiplycomplex(complex c1, complex c2)
		{
			real = (c1.real * c2.real) - (c1.img *c2.img);
			img = (c1.real * c2.img) + (c1.img * c2.real);
		}

};

int main()
{
	float x, y, a;
	cout << "Enter the real and imaginary parts of first complex number" << endl;
	cin >> x >> y;
	cout << "Enter the real and imaginary parts of second complex number" << endl;
	cin >> a;
	complex c1(x, y), c2(a), c3, c4;
	c3.addcomplex(c1, c2);
	c4.multiplycomplex(c1, c2);
	c3.print_complex();
	c4.print_complex();
	system("pause");
	return 0;

}