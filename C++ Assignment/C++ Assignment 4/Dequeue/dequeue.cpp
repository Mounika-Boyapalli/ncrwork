#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
class __dequeue__
{
	struct node *start;
public: __dequeue__();
		void Insert_Front(int);
		void Insert_Rear(int);
		int Delete_Front();
		int Delete_Rear();
		int Display_Forward();
		int Display_Backward();
		~__dequeue__();
};
__dequeue__::__dequeue__()
{
	start = NULL;
}
void __dequeue__::Insert_Front(int element)
{
	struct node *temp;
	temp = new node;
	temp->data = element;
	temp->prev = NULL;
	temp->next = start;
	if(start!=NULL)
		start->prev = temp;
	start = temp;
}
void __dequeue__::Insert_Rear(int element)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = element;
	temp->next = NULL;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		temp->prev = curr;
		curr->next = temp;
	}
	else
	{
		temp->prev = NULL;
		start = temp;
	}
}
int __dequeue__::Delete_Front()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = new node;
		temp = start;
		x = temp->data;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		start = temp->next;
		delete temp;
	}
	else
		cout << "List is Empty" << endl;
	return x;
}
int __dequeue__::Delete_Rear()
{
	struct node *temp, *curr;
	if (start != NULL)
	{
		temp = new node;
		
	}
	else
		cout << "List is Empty" << endl;
}
__dequeue__::~__dequeue__()
{
	struct node *temp;
	temp = new node;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		temp->next->prev = NULL;
		delete temp;
	}
}
class stack :private __dequeue__
{
	int top;
public: stack();
		void push(int);
		int pop();
		int peek();
		void display_stack();
		~stack();
};
stack::stack()
{
	top = -1;
}