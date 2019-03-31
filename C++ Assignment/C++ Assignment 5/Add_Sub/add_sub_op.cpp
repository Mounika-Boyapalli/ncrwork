#include<iostream>

namespace normalAddSub
{
	class c_normalAddSub
	{
		double sum;
		double difference;
	public: c_normalAddSub()
			{
				sum = 0;
				difference = 0;
			}
			int Add(double temp_var1,double temp_var2)
			{
				sum = temp_var1 + temp_var2;
				return sum;
			}
			int Sub(double temp_var1, double temp_var2)
			{
				difference = temp_var1 - temp_var2;
				return difference;
			}
	};
}