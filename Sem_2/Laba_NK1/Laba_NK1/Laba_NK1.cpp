#include <iostream>

using namespace std;

const int n = 5;

struct node {
	int marks[n];
	node* Next;
};

class List {
	node* Head;
	int num = 0;
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
	void Input() {
		node* temp = new node;
		for (int i = 0; i < n; i++) {
			cin >> temp->marks[i];
		}
		temp->Next = Head;
		Head = temp;
	}
	void Output() {
		node* temp = Head;
		cout << num;
	}
	void Count() {
		bool flag = false;
		node* temp = new node;
		for (int i = 0; i < n; i++) {
			if (temp->marks[i] < 8) {
				flag = false;
				break;
			}
			else {
				flag = true;
			}
		}
		if (flag)
			num++;
		temp->Next = Head;
		Head = temp;
	}
};

int main() {
	int N;
	List lst;
	cout << "N = ";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << i + 1 << " student marks: ";
		lst.Input();
	}
	for (int i = 0; i < N; i++) {
		lst.Count();
	}
	lst.Output();
	lst.~List();
}