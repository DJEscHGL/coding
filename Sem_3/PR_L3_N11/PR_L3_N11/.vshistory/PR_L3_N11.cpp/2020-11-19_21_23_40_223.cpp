#include <iostream>

using namespace std;

struct node {
	double element;
	node* next, *prev;
};

class List {
	node* Head, *Tail;
public:
	List() {
		Head = NULL;
		Tail = NULL;
	}
	~List() {
		while (Head != NULL) {
			Tail = Head->next;
			delete Head;
			Head = Tail;
		}
	}
	void In(double variable) {
		node* temp = new node;
		temp->next = NULL;
		temp->element = variable;
		if (Head != NULL) {
			temp->prev = Tail;
			Tail->next = temp;
			Tail = temp;
		}
		else {
			temp->prev = NULL;
			Head = Tail = temp;
		}
	}
	void Output() {
		node* temp = Head;
		while (temp != NULL) {
			cout << temp->element << " ";
			temp = temp->next;
		}
	}
	void SetElement(double ) {

	}
	void GetElement() {

	}
};

void Generate(List *obj) {

}

int main() {
}