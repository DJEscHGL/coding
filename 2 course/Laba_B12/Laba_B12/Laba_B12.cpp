#include <iostream>
#include <windows.h>

using namespace std;

struct SubUnits {
	short code;
	int planned[4];
	int pr_quartal[4];
	int completed = 0;
};

void showData(SubUnits* Unit, int amount) {
	system("cls");
	cout << "#\t" << "Code\t" << "Plan\t\t" << "Completed" << endl;
	cout << "======================================================" << endl;
	for (int i = 0; i < amount; i++) {
		cout << i + 1 << '\t' << Unit[i].code << '\t' << Unit[i].planned[0] << '/' << Unit[i].planned[1] << '/' << Unit[i].planned[2] << '/' << Unit[i].planned[3] << "\t\t"
			<< Unit[i].pr_quartal[0] << '/' << Unit[i].pr_quartal[1] << '/' << Unit[i].pr_quartal[2] << '/' << Unit[i].pr_quartal[3] << endl;
	}
}

int main() {
	int amountOfUnits;
	cout << "Amount: ";
	cin >> amountOfUnits;
	SubUnits* Unit = new SubUnits[amountOfUnits];
	for (int i = 0; i < amountOfUnits; i++) {
		cout << "Code: ";
		cin >> Unit[i].code;
		cout << "Plan per quartal: ";
		for (int j = 0; j < 4; j++) {
			cin >> Unit[i].planned[j];
		}
		cout << "Ended per quartal: ";
		for (int j = 0; j < 4; j++) {
			cin >> Unit[i].pr_quartal[j];
		}
		cin.get();
		cout << endl;
	}
	for (int i = 0; i < amountOfUnits; i++) {
		for (int j = 0; j < 4; j++) {
			if (Unit[i].pr_quartal[j] >= Unit[i].planned[j]) {
				Unit[i].completed++;
			}
		}
	}
	for (int i = 0; i < amountOfUnits - 1; i++) {
		for (int j = 0; j < amountOfUnits - i - 1; j++) {
			if (Unit[j].completed < Unit[j + 1].completed) {
				swap(Unit[j].code, Unit[j + 1].code);
				for (int q = 0; q < 4; q++) {
					swap(Unit[j].planned[q], Unit[j + 1].planned[q]);
					swap(Unit[j].pr_quartal[q], Unit[j + 1].pr_quartal[q]);
				}
				swap(Unit[j].completed, Unit[j + 1].completed);
			}
		}
	}
	showData(Unit, amountOfUnits);
}