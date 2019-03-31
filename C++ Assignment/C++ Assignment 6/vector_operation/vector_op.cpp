#include<iostream>
#include<vector>
using namespace std;
void show(vector <int> v)
{
	vector <int> ::iterator it;
	it = v.begin();
	while (it != v.end())
	{
		cout << *it++ << endl;
	}
}
int main()
{
	vector <int> v;
	int choice = 0, element = 0, index_1 = 0, index_2 = 0, temp = 0;
	while (1)
	{
		cout << "Enter your choice" << endl;
		cout << "1.Add an element" << endl << "2.Sort in ascending order" << endl;
		cout << "3.Sort in descending order" << endl << "4.Reverse the vector" << endl;
		cout << "5.Calculate the size of vector" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Enter an element" << endl;
				cin >> element;
				v.push_back(element);
				show(v);
				break;
		case 2: for (index_1 = 0; index_1 < v.size(); index_1++)
				{
					for (index_2 = index_1 + 1; index_2 < v.size(); index_2++)
					{
						if (v[index_1] > v[index_2])
						{
							temp = v[index_1];
							v[index_1] = v[index_2];
							v[index_2] = temp;
						}
					}
				}
				show(v);
				break;
		case 3: for (index_1 = 0; index_1 < v.size(); index_1++)
				{
					for (index_2 = index_1 + 1; index_2 < v.size(); index_2++)
					{
						if (v[index_1] < v[index_2])
						{
							temp = v[index_1];
							v[index_1] = v[index_2];
							v[index_2] = temp;
						}
					}
				}
				show(v);
				break;
		case 4: cout << "Writing...." << endl;
				break;
		case 5: cout << "Size of the vector is " << v.size() << endl;
			break;
		default: cout << "Invalid Option!" << endl;
		}
	}
	system("pause");
	return 0;
}