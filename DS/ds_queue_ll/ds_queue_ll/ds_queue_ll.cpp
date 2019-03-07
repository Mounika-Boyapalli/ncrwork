#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class __list__
{
	struct node *start;
public: __list__();
		void Insert_Last(int);
		int Delete_First();
		void Travel_forw();
		~__list__();
};
__list__::__list__()
{
	start = NULL;
}
void __list__::Insert_Last(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}
int __list__::Delete_First()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty";
	return x;
}
void __list__::Travel_forw()
{
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << " " << curr->data;
		curr = curr->next;
	}
}
__list__::~__list__()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}

int main()
{
	__list__ l1;
	int a, j, m;
	for (j = 0; j < 10; j++)
	{
		cout << "Choose an option" << endl << "1.Add an element" << endl;
		cout << "2.Delete an element" << endl << "3. Display" << endl;
		cin >> a;
		switch (a)
		{
		case 1: cout << "Enter the element";
			    cin >> m;
			    l1.Insert_Last(m);
			    break;
		case 2: m = l1.Delete_First();
			    cout << m;
			    break;
		case 3: l1.Travel_forw();
			    break;
		default: cout << "Invalid option" << endl;
			break;
		}
		cout << endl << endl;
	}
	system("pause");
	return 0;
}

