#include<iostream>
using namespace std;
class shape
{
	int color;
public: void get_color()
		{
			cout << "Enter the color of the shape" << endl;
			cin >> color;
		}
		virtual void get_dimen()
		{
			cout << "In Shape" << endl;
		}
		virtual void display_area()
		{
			cout << "In Shape" << endl;
		}
		void print_color()
		{
			cout << "Color is " << color << endl;
		}
};
class triangle : public shape
{
	int base = 0, height = 0;
public: void get_dimen()
		{
			cout << "Enter the dimensions of triangle" << endl;
			cin >> base >> height;
		}
		void display_area()
		{
			cout << "Area is " << (0.5*base*height) << endl;
		}
};
class square : public shape
{
	int side = 0;
public: void get_dimen()
		{
			cout << "Enter the side of square" << endl;
			cin >> side;
		}
		void display_area()
		{
			cout << "Area is " << (side*side) << endl;
		}
};
class rectangle : public shape
{
	int length = 0, breadth = 0;
public: void get_dimen()
		{
			cout << "Enter the dimensions of rectangle" << endl;
			cin >> length >> breadth;
		}
		void display_area()
		{
			cout << "Area is " << (breadth*length) << endl;
		}
};
int main()
{
	int index = 0;
	shape sobj;
	sobj.get_color();
	sobj.print_color();
	sobj.get_dimen();
	sobj.display_area();
	triangle tobj;
	tobj.get_color();
	tobj.print_color();
	tobj.get_dimen();
	tobj.display_area();
	square qobj;
	qobj.get_color();
	qobj.print_color();
	qobj.get_dimen();
	qobj.display_area();
	rectangle robj;
	robj.get_color();
	robj.print_color();
	robj.get_dimen();
	robj.display_area();
	/*shape shape_ptr[3];
	triangle t;
	square s;
	rectangle r;
	shape_ptr[0] = t;
	shape_ptr[1] = s;
	shape_ptr[2] = r;
	for (index = 0; index < 3; index++)
	{
		shape_ptr[index].get_color();
		shape_ptr[index].print_color();
		shape_ptr[index].get_dimen();
		shape_ptr[index].display_area();
	}*/
	system("pause");
	return 0;
}