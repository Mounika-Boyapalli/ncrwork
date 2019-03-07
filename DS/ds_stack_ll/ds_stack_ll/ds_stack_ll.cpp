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
		void Insert_First(int);
		int Delete_First();
		void Travel_forw();
		int peek();
		~__list__();
};
__list__::__list__()
{
	start = NULL;
}
void __list__::Insert_First(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
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
		cout << "List is empty" << endl;
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
int __list__::peek()
{
	int x = -1;
	if (start != NULL)
	{
		x = start->data;
	}
	else
		cout << "Stack is empty" << endl;
	return x;
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
	int a, m, i;
	__list__ l1;
	for (i = 0; i < 15; i++)
	{
		cout << "Choose an option" << endl << "1.Add an element" << endl;
		cout << "2.Delete an element" << endl << "3. Peek" << endl << "4. Display" << endl;
		cin >> a;
		switch (a)
		{
		case 1: cout << "Enter the element";
			cin >> m;
			l1.Insert_First(m);
			break;
		case 2: m = l1.Delete_First();
			cout << m;
			break;
		case 3: m = l1.peek();
			cout << m;
			break;
		case 4: l1.Travel_forw();
			break;
		default: cout << "Invalid option" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}