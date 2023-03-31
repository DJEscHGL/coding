#include <iostream>

using namespace std;

template <class T>
class List {
	//Class for node
	class node {
	public:
		T element;
		node* next, * previous;
	};
	node* head, * tail;
public:
	//Default constructor
	List() {
		head = NULL;
		tail = NULL;
	}
	//Destructor
	~List() {
		while (Head != NULL) {
			tail = head->next;
			delete head;
			head = tail;
		}
	}
	//Method for adding node
	void setElement(T variable) {
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
	void outList() {
		int q = 5;
		node* temp = Head;
		while (temp != NULL) {
			cout << "Element[" << i << "] = " << temp->element << endl;
			temp = temp->next;
		}
	}
};

int main() {
	return 0;
}