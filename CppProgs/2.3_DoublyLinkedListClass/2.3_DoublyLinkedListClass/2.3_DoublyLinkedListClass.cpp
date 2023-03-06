#include <iostream>

using namespace std;

template <class T>
class List {
	class node {
	public:
		T element;
		node* next, * previous;
	};
	node* head, * tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	~List() {
		while (Head != NULL) {
			tail = head->next;
			delete head;
			head = tail;
		}
	}
	void SetElement(T variable) {
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
};

int main() {
	return 0;
}