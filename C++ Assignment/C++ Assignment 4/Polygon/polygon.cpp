#include<iostream>
using namespace std;
class Polygon
{
	double dimen1;
	double dimen2;
public: Polygon()
		{
			dimen1 = 0;
			dimen2 = 0;
		}
		Polygon(int d1, int d2)
		{
			dimen1 = d1;
			dimen2 = d2;
		}
		void set_value()
		{
			cout << "Enter the dimensions" << endl;
			cin >> dimen1 >> dimen2;
		}
		double get_Dimen1()
		{
			return dimen1;
		}
		double get_Dimen2()
		{
			return dimen2;
		}
		virtual void calculate_area() = 0;
		~Polygon()
		{
			cout << "Destructing Base object" << endl;
		}
};
class Rectangle : public Polygon
{
public: Rectangle(int ht, int b):Polygon(ht,b) {  }
		void calculate_area()
		{
			cout << "Area is " << (get_Dimen1()) * (get_Dimen2()) << endl;
		}
		~Rectangle()
		{
			cout << "Destructing Rectangle object" << endl;
		}
};
class Triangle : public Polygon
{
public : Triangle() { }
		 Triangle(int base, int ht):Polygon(base,ht) {  }
		 void calculate_area()
		 {
			 cout << "Area is " << 0.5 * (get_Dimen1()) * (get_Dimen2()) << endl;
		 }
		 ~Triangle()
		 {
			 cout << "Destructing Triangle object" << endl;
		 }
};
int main()
{
	double		temp_var1, temp_var2;
	Polygon		*poly_pointer;
	Rectangle	*rect_pointer, rect_obj(5,6);
	Triangle	triangle_obj;

	triangle_obj.set_value();

	rect_pointer =	 &rect_obj;
	temp_var1	 =	 rect_pointer->get_Dimen1();
	temp_var2	 =	 rect_pointer->get_Dimen2();
	
	cout << "Dimensions of rectangle are " << endl;
	cout << temp_var1 << "  " << temp_var2 << endl;
	rect_pointer->calculate_area();

	poly_pointer =	 &triangle_obj;
	temp_var1	 =	 poly_pointer->get_Dimen1();
	temp_var2	 =	 poly_pointer->get_Dimen2();

	cout << "Dimensions of triangle are " << endl;
	cout << temp_var1 << "  " << temp_var2 << endl;
	poly_pointer->calculate_area();
	
	system("pause");
	return 0;
}