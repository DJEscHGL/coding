#include <iostream>

using namespace std;

struct node {
	int element;
	node* Next;
};

class List {
	node* Head;
public:
	List() {
		Head = NULL;
	}
	~List() {
		while (Head != NULL){
			node* temp = Head->Next;
			delete Head;
			Head = temp;
		}
	}
	void Input(int variable) {
		/*node* temp = new node;
		temp->element = variable;
		temp->Next = Head;
		Head = temp;*/
		node* temp = new node;
		temp->element = variable;
		if (Head != NULL) {
			temp->Next = Head;
			Head->Next = temp;
			Head = temp;
		}
		else {
			temp->Next = NULL;
			Head = temp;
		}
	}
	void Output() {
		node* temp = Head;
		while (temp != NULL){
			cout << temp->element << " ";
			temp = temp->Next;
		}
	}
	node* removeDuplicates()
	{
		node* t, * p, * i, * prev;
		for (p = Head; p != NULL; p = p->Next)
		{
			prev = p;
			for (i = p->Next; i != NULL; )
			{
				if (i->element == p->element)
				{
					t = prev->Next = i->Next;
					free(i);
					i = t;
					continue;
				}
				prev = i;
				i = i->Next;
			}
		}
		return Head;
	}
};

int main() {
	int N;
	int x;
	List lst;
	cout << "N = ";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cout << "x[" << i + 1 << "] = ";
		cin >> x;
		lst.Input(x);
	}
	//lst.removeDuplicates();
	lst.Output();
	lst.~List();
}