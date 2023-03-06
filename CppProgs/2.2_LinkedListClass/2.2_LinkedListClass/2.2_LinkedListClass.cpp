#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
	//Class of node
	class node {
	public:
		T element;
		node* next;
	};
	//Pointer to the head node
	node* head;
public:
	//Default constructor
	LinkedList() {
		head = NULL;
	}
	//Copy constructor
	LinkedList(LinkedList<T>& obj) {
		node* temp = obj.head;
		while (temp != NULL) {
			setElement(temp->element);
			temp = temp->next;
		}
	}
	//Constructor with parameter as value of the element of the node
	LinkedList(T var) {
		node* temp = new node;
		temp->next = NULL;
		temp->element = var;
		temp->next = head;
		head = temp;
	}
	//Destructor
	~LinkedList() {
		while (head != NULL) {
			node* temp = head->next;
			delete head;
			head = temp;
		}
	}
	//Method for adding the node 
	void setElement(T var) {
		node* temp = new node;
		temp->next = NULL;
		temp->element = var;
		temp->next = head;
		head = temp;
	}
	//Method for deleting first element
	void delFirst() {
		node* temp = head;
		head = head->next;
		delete temp;
	}
	//Method for output
	void outList() {
		node* temp = head;
		int i = 0;
		cout << endl;
		while (temp != NULL) {
			cout << "Element[" << i << "] = " << temp->element << endl;
			temp = temp->next;
			i++;
		}
	}
	//Method for searching node by value of an element
	int searchElement(T var) {
		node* temp = head;
		int i = 0;
		while (temp != NULL) {
			if (temp->element == var) {
				return i;
			}
			temp = temp->next;
			i++;
		}
		return -1;
	}
	//Method for deleting list
	void deleteList() {
		node* temp = head;
		while (temp != NULL) {
			head = temp->next;
		}
	}
	//Method for initializing list by first node (???)
	void initFirstElement(char var) {
		node* temp = new node;
		temp->next = NULL;
		temp->element = var;
		temp->next = head;
		head = temp;
	}
	//Method for deleting node in list
	void deleteNode(int num) {
		if (num == 0) {
			delFirst();
		}
		else
		{
			node* previous = head;
			for (int i = 0; i < num - 1; i++) {
				previous = previous->next;
			}
			node* toDel = previous->next;
			previous->next = toDel->next;
			delete toDel;
		}
	}
	//Operator overloading for indexing
	node* operator[](const int index) {
		node* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp;
	}
};

int main() {
	setlocale(0, "");
	LinkedList<char> L1, L2;
	int sizeL1, sizeL2;
	cout << "L1 size = ";
	cin >> sizeL1;
	cout << "L2 size = ";
	cin >> sizeL2;
	cout << "L1 nums:" << endl;
	for (int i = 0; i < sizeL1; i++) {
		char var;
		cin >> var;
		L1.setElement(var);
	}
	cout << "L2 nums:" << endl;
	for (int i = 0; i < sizeL2; i++) {
		char var;
		cin >> var;
		L2.setElement(var);
	}
	LinkedList<char> L(L1);
	for (int i = 0; i < sizeL1; i++){
		int ind;
		ind = L2.searchElement(L1[i]->element);
		if (ind != -1) {
			L2.deleteNode(ind);
			sizeL2--;
		}
	}
	for (int i = 0; i < sizeL2; i++) {
		L.setElement(L2[i]->element);
	}
	L.outList();
	return 0;
}