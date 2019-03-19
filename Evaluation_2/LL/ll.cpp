#include<iostream>
using namespace std;
//structure is defined
struct node
{
	int data;
	struct node *next;
};
//class is defined  
class s_list
{
	struct node *start;
public: s_list();
		void Insert_First(int);
		void Insert_Position(int, int);
		void Delete_Spec(int);
		void Travel_Forward();
		void Travel_Back();
		void reverse_list();
		~s_list();
		friend void print(struct node*);
};
//constructor
s_list::s_list()
{
	start = NULL;
}
//Insert first position
void s_list::Insert_First(int element)
{
	struct node *temp;
	temp = new node;
	temp->data = element;
	if (start == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		temp->next = start;
	}
	start = temp;
}
//Insert at nth position
void s_list::Insert_Position(int element, int pos)
{
	int count = 1;
	struct node *temp, *curr;
	temp = new node;
	temp->data = element;
	curr = start;
	if (start != NULL)
	{
		while (curr != NULL && count != pos-1)
		{
			count++;
			curr = curr->next;
		}
		if (curr != NULL)   //reached (n-1)th position
		{
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "Position not found" << endl;
	}
	else
		cout << "List is empty" << endl;
}
//Deleting specific element
void s_list::Delete_Spec(int element)
{
	struct node *curr, *temp;
	temp = new node;
	if (start != NULL)
	{
		if (start->data == element)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			curr = start;
			if (curr->next != NULL && curr->next->data != element)
				curr = curr->next;
			if (curr->next != NULL)  //element is found
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "Element not found" << endl;
		}
	}
	else
		cout << "List is empty " << endl;
}
//display in forward direction
void s_list::Travel_Forward()
{
	struct node *temp;
	temp = new node;
	temp = start;
	while (temp!= NULL)
	{
		cout << " " << temp->data;
		temp = temp->next;
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
//display in reverse direction
void s_list::Travel_Back()
{
	if (start != NULL)
		print(start);
}
//reversing list
void s_list::reverse_list()
{
	struct node *temp, *reverse;
	reverse = NULL;
	if (start != NULL || start->next != NULL)
	{
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			temp->next = reverse;
			reverse = temp;
		}
		start = reverse;
	}
}
//destructor
s_list::~s_list()
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
	s_list list;
	int choice = 0, value = 0, position = 0;
	while (1)
	{
		cout << endl;
		cout << "Enter your choice" << endl;
		cout << "1.Insert first" << endl << "2.Insert at a position" << endl << "3.Delete an element" << endl << "4.Print in forward direction" << endl;
		cout << "5.Travel in backward direction" << endl << "6.Reverse the list" << endl << "7.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1: cout << "Enter the element" << endl;
					cin >> value;
					list.Insert_First(value);
					break;
			case 2: cout << "Enter an element" << endl;
					cin >> value;
					cout << "Enter the position";
					cin >> position;
					list.Insert_Position(value,position);
					break;
			case 3: cout << "Enter an element" << endl;
					cin >> value;
					list.Delete_Spec(value);
					break;
			case 4: list.Travel_Forward();
					break;
			case 5: list.Travel_Back();
					break;
			case 6: list.reverse_list();
					break;
			case 7: exit(0);
			default: cout << "Invalid Option" << endl;
		}
	}
	system("pause");
	return 0;
}