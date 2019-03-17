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
		friend complex addcomplex(complex, complex);
		friend complex multiplycomplex(complex, complex);
};
complex addcomplex(complex c1, complex c2)
{
	complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	return temp;
}
complex multiplycomplex(complex c1, complex c2)
{
	complex temp;
	temp.real = (c1.real * c2.real) - (c1.img *c2.img);
	temp.img = (c1.real * c2.img) + (c1.img * c2.real);
	return temp;
}

int main()
{
	float real_1 = 0, imaginary_1 = 0, complex_2 = 0;
	cout << "Enter the real and imaginary parts of first complex number" << endl;
	cin >> real_1 >> imaginary_1;
	cout << "Enter either the real or imaginary part of second complex number whose real and imaginary parts are equal" << endl;
	cin >> complex_2;
	complex object_1(real_1, imaginary_1), object_2(complex_2), object_3, object_4;
	object_3 = addcomplex(object_1, object_2);
	object_4 = multiplycomplex(object_1, object_2);
	cout << "Sum of the two complex numbers is" << endl;
	object_3.print_complex();
	cout << "Product of the two complex numbers is" << endl;
	/*object_4.print_complex();
	object_4.~complex();
	object_3.~complex();
	object_2.~complex();
	object_1.~complex();*/
	system("pause");
	return 0;
}