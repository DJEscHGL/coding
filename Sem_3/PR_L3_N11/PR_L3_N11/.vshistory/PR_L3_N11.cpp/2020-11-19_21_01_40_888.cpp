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
		while (Head != NULL) {
			node* temp = Head->Next;
			delete Head;
			Head = temp;
		}
	}
	void Input(int variable) {
		node* temp = new node;
		temp->element = variable;
		temp->Next = Head;
		Head = temp;
	}
	void Output() {
		node* temp = Head;
		while (temp != NULL) {
			cout << temp->element << " ";
			temp = temp->Next;
		}
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
	lst.Output();
	lst.~List();
}