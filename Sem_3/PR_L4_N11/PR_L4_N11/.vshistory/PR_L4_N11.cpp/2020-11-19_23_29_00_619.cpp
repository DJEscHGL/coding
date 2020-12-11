#include <iostream>
#include <Windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

template <class T>
class List {
	class node {
	public:
		T element;
		node* next, *prev;
	};
	node* Head, * Tail;
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
	void Output() {
		int q = 5;
		node* temp = Head;
		while (temp != NULL) {
			SetConsoleTextAttribute(hConsole, q);
			cout << temp->element << " ";
			temp = temp->next;
			if (q == 5)
				q = 6;
			else
				q = 5;
		}
		SetConsoleTextAttribute(hConsole, 7);
	}
	T GetHeadElement(int i) {
		node* temp = Head;
		while (i > 0) {
			temp = temp->next;
			i--;
		}
		return temp->element;
	}
	T GetTailElement(int i) {
		node* temp = Tail;
		while (i > 0) {
			temp = temp->prev;
			i--;
		}
		return temp->element;
	}
};

void ListOfDouble() {
	List<double> list1, list2;
	int n;
	double variable;
	cout << "Количество элементов списка: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Element[" << i + 1 << "] = ";
		cin >> variable;
		list1.SetElement(variable);
	}
	for (int i = 0; i < n; i++) {
		list2.SetElement(list1.GetHeadElement(i));
		list2.SetElement(list1.GetTailElement(i));
	}
	cout << endl;
	list2.Output();
	cout << endl;
}

void ListOfInt() {
	List<int> list1, list2;
	int n;
	double variable;
	cout << "Количество элементов списка: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Element[" << i + 1 << "] = ";
		cin >> variable;
		list1.SetElement(variable);
	}
	for (int i = 0; i < n; i++) {
		list2.SetElement(list1.GetHeadElement(i));
		list2.SetElement(list1.GetTailElement(i));
	}
	cout << endl;
	list2.Output();
	cout << endl;
}

int main() {
	setlocale(0, "");
	bool flag = true;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Двусвязный список типа int\n2.Двусвязный список типа double\n";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			ListOfInt();
			system("pause");
			break;
		case 2:
			system("cls");
			ListOfDouble();
			system("pause");
			break;
		}
	}
}