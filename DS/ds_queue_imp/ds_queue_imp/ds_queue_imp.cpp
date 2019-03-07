#include <iostream>
using namespace std;
struct __queue__
{
	int r;
	int f;
	int *s;
	int size;
};
class _queue_
{
	struct __queue__ que;
	public: _queue_();
			void enque(int);
			int deque();
			bool Overflow();
			bool Underflow();
			void display();
			~_queue_();
			void getsize(int);
};
_queue_::_queue_()
{
	que.r = -1;
	que.f = -1;
	que.s = NULL;
	que.size = 0;
}
void _queue_::getsize(int n)
{
	que.size = n;
	que.s = new int[n];
}
bool _queue_::Overflow()
{
	return (que.r == (que.size - 1));
}
bool _queue_::Underflow()
{
	return ((que.r == -1) && (que.f == -1));
}
void _queue_::enque(int ele)
{
	if (!Overflow())
	{
		if (que.f == -1)
			que.f++;
		que.r++;
		que.s[que.r] = ele;
	}
	else
	{
		cout << "Queue Overflow" << endl;
	}
}
int _queue_::deque()
{
	int x = -999;
	if (!Underflow())
	{
		if (que.f < que.r)
		{
			x = que.s[que.f];
			que.f++;
		}
		else if (que.f == que.r)
		{
			x = que.s[que.f];
			que.f++;
			que.f = -1;
			que.r = -1;
		}
	}
	else
		cout << "Queue underflow" << endl;
	return x;
}
void _queue_::display()
{
	int i;
	for (i = que.f; i <= que.r; i++)
	{
		cout << " " << que.s[i];
	}
}
_queue_::~_queue_()
{
	delete que.s;
}

int main()
{
	int a, m, n, siz, j;
	_queue_ q1;
	cout << "Enter the size of queue";
	cin >> siz;
	q1.getsize(siz);
	for (j = 0; j < 10; j++)
	{
		cout << "Choose an option" << endl << "1.Add an element" << endl;
		cout << "2.Delete an element"  << endl << "3. Display" << endl;
		cin >> a;
		switch (a)
		{
		case 1: cout << "Enter the element";
			    cin >> m;
			    q1.enque(m);
			    break;
		case 2: n = q1.deque();
			    cout << n;
			    break;
		case 3: q1.display();
			    break;
		default: cout << "Invalid option" << endl;
			break;
		}
		cout << endl << endl;
	}
	system("pause");
	return 0;
}