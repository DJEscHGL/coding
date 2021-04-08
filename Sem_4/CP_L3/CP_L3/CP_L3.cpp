#include <iostream>
#include <fstream>

using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

class Queue {
public:
	class node {
	public:
		double info;
		node* p;
	};
	node* top, * bottom;
	Queue() {
		top = NULL;
		bottom = NULL;
	}
	~Queue() {
		while (top != NULL) {
			bottom = top->p;
			delete top;
			top = bottom;
		}
	}
	void SetElement(double variable) {
		node* temp = new node;
		temp->p = NULL;
		temp->info = variable;
		if (top != NULL) {
			bottom->p = temp;
			bottom = temp;
		}
		else {
			top = bottom = temp;
		}
	}
	void Output() {
		node* temp = top;
		while (temp != NULL) {
			cout << temp->info << " ";
			temp = temp->p;
		}
	}
	double GetHeadElement(int i) {
		node* temp = top;
		while (i > 0) {
			temp = temp->p;
			i--;
		}
		return temp->info;
	}
};

int main() {
	setlocale(0, "");
	Queue list;
	int n;
	double variable, a, b;
	input >> n;
	for (int i = 0; i < n; i++) {
		input >> variable;
		list.SetElement(variable);
	}
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	for (int i = 0; i < n; i++) {
		if (list.GetHeadElement(i) < a)
			output << list.GetHeadElement(i) << " ";
	}
	for (int i = 0; i < n; i++) {
		if (list.GetHeadElement(i) >= a && list.GetHeadElement(i) <= b)
			output << list.GetHeadElement(i) << " ";
	}
	for (int i = 0; i < n; i++) {
		if (list.GetHeadElement(i) > b)
			output << list.GetHeadElement(i) << " ";
	}
	list.~Queue();
}