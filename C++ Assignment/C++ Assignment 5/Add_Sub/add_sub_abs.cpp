#include<iostream>

namespace absAddSub
{
	class c_absAddSub
	{
		double sum;
		double difference;
	public : c_absAddSub()
			 {
				sum = 0;
				difference = 0;
			 }
			 double Add(double temp_var1, double temp_var2)
			 {
				 if (temp_var1 < 0)
					 temp_var1 = -1 * temp_var1;
				 if (temp_var2 < 0)
					 temp_var2 = -1 * temp_var2;
				 sum = temp_var1 + temp_var2;
				 return sum;
			 }
			 double Sub(double temp_var1, double temp_var2)
			 {
				 if (temp_var1 < 0)
					 temp_var1 = -1 * temp_var1;
				 if (temp_var2 < 0)
					 temp_var2 = -1 * temp_var2;
				 difference = temp_var1 - temp_var2;
				 return difference;
			 }
	};
}