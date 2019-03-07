#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	struct node *left, *right;
};
class _BST_
{
	struct node *start;
public: _BST_();
		node * Insert(int,node *);
		node * Delete_ele(int, node *);
		void Inorder();
		void Preorder();
		void Postorder();
		~_BST_();
		int FindMax(node *);
		int FindMin(node *);
		int Height(node *);
		int NLN(node *);
		int NNLN(node *);
		friend void Print_Inorder(node *);
		friend void Print_Preorder(node *);
		friend void Print_Postorder(node *);
		friend void delete_node(node *);
};
_BST_::_BST_()
{
	start = NULL;
}
int _BST_::NLN(node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	else
		return(NLN(curr->left) + NLN(curr->right));
}
int _BST_::NNLN(node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 0;
	else
		return(NNLN(curr->left) + NNLN(curr->right) + 1);
}
int _BST_::FindMin(node *curr)
{
	if (curr != NULL)
	{
		while (curr->left != NULL)
			curr = curr->left;
		return curr->data;
	}
	else
		return -1;
}
int _BST_::FindMax(node *curr)
{
	if (curr != NULL)
	{
		while (curr->right != NULL)
			curr = curr->right;
		return curr->data;
	}
	else
		return -1;
}
int _BST_::Height(node *curr)
{
	if (curr == NULL)
		return -1;
	else
		return(max(Height(curr->left), Height(curr->right)) + 1);
}
void Print_Inorder(node *curr)
{
	if (curr != NULL)
	{
		Print_Inorder(curr->left);
		cout << curr->data;
		Print_Inorder(curr->right);
	}
}
void _BST_::Inorder()
{
	
	if (start != NULL)
		Print_Inorder(start);
}
void Print_Preorder(struct node *curr)
{
	if (curr != NULL)
	{
		cout << curr->data;
		Print_Preorder(curr->left);
		Print_Preorder(curr->right);
	}
}
void Print_Postorder(node *curr)
{
	if (curr != NULL)
	{
		Print_Postorder(curr->left);
		Print_Postorder(curr->right);
		cout << curr->data;
	}
}
void _BST_::Preorder()
{
	if (start != NULL)
		Print_Preorder(start);
}
void _BST_::Postorder()
{
	if (start != NULL)
		Print_Postorder(start);
}
void delete_node(node *curr)
{
	if (curr != NULL)
	{
		delete_node(curr->left);
		delete_node(curr->right);
		delete curr;
	}
}
_BST_::~_BST_()
{
	if (start != NULL)
		delete_node(start);
}
node * _BST_::Insert(int ele, node *curr)
{
	if (curr == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else
	{
		if (ele < curr->data)
			curr->left = Insert(ele, curr->left);
		else
			curr->right = Insert(ele, curr->right);
		return curr;
	}
}
node * _BST_::Delete_ele(int ele, node *curr)
{
	if (curr != NULL)
	{
		if (ele > curr->data)
			curr->right = Delete_ele(ele, curr->right);
		else
		{
			if (ele < curr->data)
				curr->left = Delete_ele(ele, curr->left);
			else
			{
				if (curr->left != NULL && curr->right != NULL)
				{
					curr->data = FindMax(curr->left);
					curr->left = Delete_ele(curr->data, curr->left);
				}
				else
				{
					struct node *temp;
					temp = curr;
					if (curr->left == NULL)
						curr = curr->right;
					else
						curr = curr->left;
					delete temp;
				}
			}
		}
	}
	return curr;
}
int main()
{
	int choice, ele;
	_BST_ b1;
	while (1)
	{
		cout << "Enter the choice: " << endl;
		cout << "1. Insert into a tree" << endl << "2. Delete an element from the tree" << endl;
		cout << "3. Display tree in inorder" << endl << "4. Display tree in preorder" << endl << "5. Display tree in postorder" << endl;
		cout << "6. Calculate number of leafnodes" << endl << "7. Calculate number of non-leafnodes" << endl;
		cout << "8. Find height of a node" << endl << "9. Find maximum element in the tree" << endl << "10. Find minimum element in the tree" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Enter the element to be inserted";
			    cin >> ele;
				b1.Insert(ele);
			    break;
		}
	}
	system("pause");
	return 0;
}