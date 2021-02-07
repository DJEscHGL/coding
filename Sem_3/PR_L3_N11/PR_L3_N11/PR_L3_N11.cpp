#include <iostream>
#include <Windows.h>
#include <fstream>
#include <locale>

using namespace std;
ifstream input("input.txt");
ofstream output("output.txt");

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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
		int q = 5;
		node* temp = Head;
		while (temp != NULL) {
			SetConsoleTextAttribute(hConsole, q);
			output << temp->element << " ";
			cout << temp->element << " ";
			temp = temp->next;
			if (q == 5)
				q = 6;
			else
				q = 5;
		}
		SetConsoleTextAttribute(hConsole, 7);
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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		if (!input.is_open())
			throw true;
		else
			throw false;
	}
	catch (bool che) {
		if (che)
			input.open("input.txt");
		else
			cout << "Файл input.txt открыт" << endl;
	}
	try {
		if (!output.is_open())
			throw true;
		else
			throw false;
	}
	catch (bool che) {
		if (che)
			input.open("output.txt");
		else
			cout << "Файл output.txt открыт" << endl;
	}
	List list1, list2;
	int n;
	double variable;
	//cout << "Количество элементов списка: ";
	input >> n;
	for (int i = 0; i < n; i++) {
		//cout << "Element[" << i + 1 << "] = ";
		input >> variable;
		list1.SetElement(variable);
	}
	for (int i = 0; i < n; i++) {
		list2.SetElement(list1.GetHeadElement(i));
		list2.SetElement(list1.GetTailElement(i));
	}
	output << endl;
	cout << endl;
	list2.Output();
	cout << endl;
	output << endl;
	list1.Output();
	cout << endl;
	output << endl;
	input.close();
	output.close();
}