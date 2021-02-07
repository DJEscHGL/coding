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
	if (input.is_open())
	{
		cout << "Файл input.txt открытый" << endl;
	}
	else
		input.open("input.txt");
	if (output.is_open())
	{
		cout << "Файл output.txt открытый" << endl;
	}
	else
		output.open("output.txt");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List list1, list2;
	int n;
	double variable;
	//cout << "Количество элементов списка: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		//cout << "Element[" << i + 1 << "] = ";
		cin >> variable;
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
	for (int i = 0; i < n; i++) {
		cout << list1.GetHeadElement(i) << " ";
		output << list1.GetHeadElement(i) << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << list1.GetTailElement(i) << " ";
		output << list1.GetTailElement(i) << " ";
	}
	input.close();
	output.close();
}