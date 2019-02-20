#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
class __dll__
{
	struct node *start;
public: __dll__();
		void Insert_First(int);
		void Insert_Last(int);
		void Insert_After(int, int);
		void Insert_Before(int, int);
		int Delete_First();
		int Delete_Last();
		void Delete_Spec(int);
		void Travel_forw();
		void Travel_Back();
		~__dll__();
};
__dll__::__dll__()
{
	start = NULL;
}
void __dll__::Insert_First(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->prev = NULL;
	temp->next = start;
	if (start != NULL)
		start->prev = temp;
	start = temp;
}
void __dll__::Insert_Last(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		temp->prev = curr;
		curr->next = temp;
	}
}
void __dll__::Insert_After(int ele, int sele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = new node;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->prev = curr;
			temp->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = temp;
			curr->next = temp;
		}
		else
			cout << "Element Not Found" << endl;
	}
	else
		cout << "List is empty" << endl;
}
void __dll__::Insert_Before(int ele, int sele)
{
	if (start != NULL)
	{
		struct node *curr, *temp;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			temp = new node;
			temp->data = ele;
			temp->prev = curr->prev;
			temp->next = curr;
			if (curr->prev != NULL)
				curr->prev->next = temp;
			else
				start = temp;
			curr->prev = temp;
		}
		else
			cout << "Element not found" << endl;
	}
	else
		cout << "List is empty" << endl;
}
int __dll__::Delete_First()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty";
	return x;
}
int __dll__::Delete_Last()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *temp, *curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		x = curr->data;
		if (curr->prev != NULL)
			curr->prev->next = NULL;
		else
			start = NULL;
		delete curr;
	}
	else
		cout << "List is empty";
	return x;
}
void __dll__::Delete_Spec(int ele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != ele)
			curr = curr->next;
		if (curr != NULL)
		{
			if (curr->prev != NULL)
				curr->prev->next = curr->next;
			else
				start = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			delete curr;
		}
		else
			cout << "Element not found" << endl;
	}
	else
		cout << "List is empty";
}
void __dll__::Travel_forw()
{
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << " " << curr->data;
		curr = curr->next;
	}
}
void __dll__::Travel_Back()
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		while (curr != NULL)
		{
			cout << " " << curr->data;
			curr = curr->prev;
		}
	}
}
__dll__::~__dll__()
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
	__dll__ l1;
	int i, a, m, e;
	for (i = 0; i < 15; i++)
	{
		cout << "Choose an option" << endl << "1.Add an element at the beginning" << endl;
		cout << "2.Add an element at the last" << endl << "3. Add an element after an element" << endl << "4. Add an element before an element" << endl;
		cout << "5. Delete an element at the beginning" << endl << "6. Delete an element at the last" << endl << "7. Delete a specific element" << endl;
		cout << "8. Display in forward" << endl << "9.Display in backward" << endl;
		cin >> a;

		switch (a)
		{
		case 1: cout << "Enter the element";
			cin >> m;
			l1.Insert_First(m);
			break;
		case 2: cout << "Enter the element";
			cin >> m;
			l1.Insert_Last(m);
			break;
		case 3: cout << "Enter the element";
			cin >> m;
			cout << "Enter the element after which to be added";
			cin >> e;
			l1.Insert_After(m, e);
			break;
		case 4: cout << "Enter the element";
			cin >> m;
			cout << "Enter the element before which to be added";
			cin >> e;
			l1.Insert_Before(m, e);
			break;
		case 5: m = l1.Delete_First();
			cout << m;
			break;
		case 6: m = l1.Delete_Last();
			cout << m;
			break;
		case 7: cout << "Enter the element to be deleted" << endl;
			cin >> m;
			l1.Delete_Spec(m);
			break;
		case 8: l1.Travel_forw();
			break;
		case 9: l1.Travel_Back();
			break;
		default: cout << "Invalid option" << endl;
			break;
		}
		cout << endl << endl;
	}
	system("pause");
	return 0;
}