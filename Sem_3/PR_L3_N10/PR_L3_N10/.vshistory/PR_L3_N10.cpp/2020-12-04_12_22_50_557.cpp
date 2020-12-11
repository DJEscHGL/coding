#include <iostream>
#include <Windows.h>

using namespace std;

struct node
{
	int element;
	node* Next;
};

class List
{
	node* Head;
public:
	List()
	{
		Head = NULL;
	}
	~List()
	{
		while (Head != NULL) {
			node* temp = Head->Next;
			delete Head;
			Head = temp;
		}
	}
	void Input(int variable)
	{
		node* temp = new node;
		temp->Next = NULL;
		temp->element = variable;
		temp->Next = Head;
		Head = temp;
	}
	void Output()
	{
		node* temp = Head;
		while (temp != NULL)
		{
			cout << temp->element << " ";
			temp = temp->Next;
		}
		cout << "\n";
	}
	int GetHeadElement(int i)
	{
		node* temp = Head;
		while (i > 0) {
			temp = temp->Next;
			i--;
		}
		return temp->element;
	}
};

int main()
{
	setlocale(0, "");
	List list1, list2;
	int size1, size2 = 0;
	int variable;
	int buff = 0;
	cout << "Количество элементов списка: ";
	cin >> size1;
	for (int i = 0; i < size1; i++) {
		cout << "List1[" << i + 1 << "] = ";
		cin >> variable;
		list1.Input(variable);
	}
	for (int i = 0; i < size1; i++) {
		if (buff < list1.GetHeadElement(i))
			buff == list1.GetHeadElement(i);
	}
	for (int i = 0; i < size1; i++) {
		if (buff == list1.GetHeadElement(i))
			list2.Input(i);
	}
	system("cls");
	cout << "List1: ";
	list1.Output();
	cout << "List2: ";
	list2.Output();
	cout << endl;
}