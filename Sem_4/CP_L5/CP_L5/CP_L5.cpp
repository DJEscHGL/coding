#include <iostream>
#include <fstream>

using namespace std;

class Stack {
public:
	class node {
	public:
		int info;
		node* p;
	};
	node* top;
	Stack() {
		top = NULL;
	}
	~Stack() {
		while (top != NULL) {
			node* temp = top->p;
			delete top;
			top = temp;
		}
	}
	void SetElement(int variable) {
		node* temp = new node;
		temp->p = NULL;
		temp->info = variable;
		temp->p = top;
		top = temp;
	}
	void DeleteElement(int n, int size) {
		node* temp = top, * prev = NULL;
		int i = 0;
		while (temp && i < n)
		{
			i++;
			prev = temp;
			temp = temp->p;
		}
		if (!temp)
		{
			return;
		}
		if (top == temp)
		{
			top = temp->p;
		}
		else
		{
			if (prev) prev->p = temp->p;
		}
		size--;
		free(temp);
	}
	void Output() {
		node* temp = top;
		while (temp != NULL) {
			cout << temp->info << " ";
			temp = temp->p;
		}
	}
	void Replace(int size) {
		node* minn = top;
		node* maxx = top;
		node* element = new node;
		node* temp = new node;
		int max_p, min_p, i = 0;
		int max = top->info, min = top->info;
		while (maxx != NULL) {
			if (maxx->info >= max) {
				max = maxx->info;
				max_p = i;
			}
			maxx = maxx->p;
			i++;
		}
		i = 0;
		while (minn != NULL) {
			if (minn->info <= min) {
				min = minn->info;
				min_p = i;
			}
			minn = minn->p;
			i++;
		}
		i = size;
		DeleteElement(max_p, size);
		temp->p = NULL;
		temp->info = max;
		temp->p = top;
		top = temp;
		node* buff = top;
		while (i > 1) {
			buff = buff->p;
			i--;
		}
		element->info = min;
		element->p = NULL;
		buff->p = element;
		DeleteElement(min_p, size);
	}
};

int main() {
	setlocale(0, "");
	Stack stack;
	int a, n, k;
	cout << "Размер стека: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		stack.SetElement(a);
	}
	stack.Replace(n);
	stack.Output();
	cout << endl;
	cout << "Какой удалить элемент: ";
	cin >> k;
	stack.DeleteElement(k, n);
	stack.Output();
	stack.~Stack();
}