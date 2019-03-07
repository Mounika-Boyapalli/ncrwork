#include<iostream>
using namespace std;
struct node
{
	int coeff;
	int power;
	struct node *next;

};
class polynomial
{
	struct node *start;
public:
	polynomial();
	void Insert_First(int, int);
	void Display();
	void Add(polynomial, polynomial);
	~polynomial();

};
polynomial::polynomial()
{
	start = NULL;
}
void polynomial::Insert_First(int ele1, int ele2)
{
	struct node *temp;
	temp = new node;
	temp->coeff = ele1;
	temp->power = ele2;
	temp->next = start;
	start = temp;
}
void polynomial::Display()
{
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->coeff << " - " << curr->power << endl;
		curr = curr->next;
	}
}
void polynomial::Add(polynomial p1, polynomial p2)
{
	struct node*curr1, *curr2;
	curr1 = p1.start;
	curr2 = p2.start;
	if (p1.start == NULL && p2.start == NULL)
		cout << "Lists are empty" << endl;
	while (curr1 != NULL && curr2 != NULL)//
	{
		if (curr1->power == curr2->power)
		{
			Insert_First((curr1->coeff) + (curr2->coeff), curr1->power);
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		else if (curr1->power > curr2->power)
		{
			Insert_First(curr1->coeff, curr1->power);
			curr1 = curr1->next;
		}
		else if (curr1->power < curr2->power)
		{
			Insert_First(curr2->coeff, curr2->power);
			curr2 = curr2->next;
		}

	}
	while (curr1 != NULL) {
		Insert_First(curr1->coeff, curr1->power);
		curr1 = curr1->next;
	}
	while (curr2 != NULL) {
		Insert_First(curr2->coeff, curr2->power);
		curr2 = curr2->next;
	}
}
polynomial::~polynomial()
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
	polynomial p1, p2, p3;
	int choice, coef, pwr;
	while (1)
	{
		cout << "Enter the elements" << endl;
		cout << "1. Add elements to first polynomial" << endl << "2. Add elements to second polynomial" << endl;
		cout << "3. Add both the polynomials" << endl << "4. Display the polynomials" << endl << "5. Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Enter the coeffient in first polynomial" << endl;
			   cin >> coef;
			   cout << "Enter its power" << endl;
			   cin >> pwr;
			   p1.Insert_First(coef, pwr);
			   break;
		case 2:cout << "Enter the coeffient in second polynomial" << endl;
			   cin >> coef;
			   cout << "Enter its power" << endl;
			   cin >> pwr;
			   p2.Insert_First(coef, pwr);
			   break;
		case 3:p3.Add(p1, p2);
			   break;
		case 4:cout << "First Polynomial: " << endl;
			   p1.Display();
			   cout << "Second Polynomial: " << endl;
			   p2.Display();
			   cout << "Sum of the 2 polynomials is: " << endl;
			   p3.Display();
			   break;
		case 5:exit(0);
		}
	}
	system("pause");
	return 0;
}