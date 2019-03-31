#include <iostream>
#include "add_sub_abs.cpp"
#include "add_sub_op.cpp"
using namespace std;
using namespace normalAddSub;
using namespace absAddSub;

int main()
{
	absAddSub::c_absAddSub abs_obj;
	normalAddSub::c_normalAddSub normal_obj;
	double op_var1 = 0, op_var2 = 0, result = 0;
	int  choice = 0;
	cout << "Enter the variables to be operated upon" << endl;
	cin >> op_var1 >> op_var2;
	while (1)
	{
		cout << "Enter your choice " << endl << "1.Add" << endl << "2.Sub" << endl << "3.Add abs values" << endl << "4.Sub abs values" << endl;
		cin >> choice;
		if (sizeof(choice) == 1)
		{
			cout << "Incorrect Choice Type!" << endl;
		}
		if (sizeof(choice) == 4)
		{
			switch (choice)
			{
			case 1: result = normal_obj.Add(op_var1, op_var2);
				cout << "Sum is " << result << endl;
				break;
			case 2: result = normal_obj.Sub(op_var1, op_var2);
				cout << "Difference is " << result << endl;
				break;
			case 3: result = abs_obj.Add(op_var1, op_var2);
				cout << "Absolute sum is " << result << endl;
				break;
			case 4: result = abs_obj.Sub(op_var1, op_var2);
				cout << "Absolute difference is " << result << endl;
				break;
			default: cout << "Invalid Choice" << endl;
			}
		}
		else
		{
			cout << "Incorrect Choice Type!" << endl;
		}
	}
	system("pause");
	return 0;
}