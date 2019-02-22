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
		void Insert_Last(int);
		void Insert_After(int, int);
		void Insert_Before(int, int);
		void Delete_Spec(int);
		void Travel_forw();
		void Travel_Back();
		void Self_Adjust(int);
		void reverse();
		~__list__();
		friend void print(struct node*);
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
void __list__::Insert_After(int ele, int sele)
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
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "Element Not Found" << endl;
	}
	else
		cout << "List is empty" << endl;
}
void __list__::Insert_Before(int ele, int sele)
{
	if (start != NULL)
	{
		if (start->data == sele)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next != NULL && curr->next->data != sele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = ele;
				temp->next = curr->next;
				curr->next = temp;
			}
			else
				cout << "Element Not Found" << endl;
		}
	}
	else
		cout << "List is empty" << endl;
}
void __list__::Delete_Spec(int ele)
{
	struct node *temp, *curr;
	if (start != NULL)
	{
		if (start->data == ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			curr = start;
			while (curr->next != NULL && curr->next->data != ele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "Element is not found";
		}
	}
	else
		cout << "List is empty";
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
void __list__::Travel_Back()
{
	if (start != NULL)
		print(start);
}
void __list__::reverse()
{
	struct node *temp, *rev;
	rev = NULL;
	if (start != NULL || start->next != NULL)
	{
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			temp->next = rev;
			rev = temp;
		}
		start = rev;
	}
}
void __list__::Self_Adjust(int e)
{
	int self;
	struct node *temp, *curr;
	if (start != NULL)
	{
		if (start->data != e)
		{
			curr = start;
			while (curr->next != NULL && curr->next->data != e)
				curr = curr->next;
			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
				Insert_First(e);
			}
			else
				cout << "Element is not found";
		}
	}
	else
		cout << "List is empty";
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
void print(struct node*curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << " " << curr->data;
	}
}
int main()
{
	__list__ l1;
	int i, j, m, a, e;
	for (i = 0; i < 15; i++)
	{
		cout << "Choose an option" << endl << "1.Add an element at the beginning" << endl;
		cout << "2.Add an element at the last" << endl << "3. Add an element after an element" << endl << "4. Add an element before an element" << endl;
		cout << "5. Delete a specific element" << endl;
		cout << "6. Display in forward" << endl << "7.Display in backward" << endl << "8. Reverse the list" << endl << "9. Self adjust" << endl;
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
		case 5: cout << "Enter the element to be deleted" << endl;
			cin >> m;
			l1.Delete_Spec(m);
			break;
		case 6: l1.Travel_forw();
			break;
		case 7: l1.Travel_Back();
			break;
		case 8: l1.reverse();
			break;
		case 9: cout << "Enter the element to be self adjusted" << endl;
			cin >> e;
			l1.Self_Adjust(e);
			break;
		default: cout << "Invalid option" << endl;
			break;
		}
		cout << endl << endl;
	}
	system("pause");
	return 0;
}