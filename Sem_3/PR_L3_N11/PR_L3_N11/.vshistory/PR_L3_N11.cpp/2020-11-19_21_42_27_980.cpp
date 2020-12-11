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
	void SetElement(double variable) {
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
	double GetHeadElement(int i) {
		node* temp = Head;
		while (i > 0) {
			temp = temp->next;
			i--;
		}
		return temp->element;
	}
	double GetTailElement(int i) {
		node* temp = Tail;
		while (i > 0) {
			temp = temp->prev;
			i--;
		}
		return temp->element;
	}
};

void Generate(List *obj, List *newobj, int n) {
	for (int i = 0; i < n; i++) {
		newobj->SetElement(obj->GetHeadElement(i));
		newobj->SetElement(obj->GetTailElement(i));
	}
}

int main() {
	List list1, list2;
	int n;
	double variable;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> variable;
		list1.SetElement(variable);
	}
	Generate(&list1, &list2, n);
	cout << "/////////////////";
	list2.Output();
}