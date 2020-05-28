#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

struct SubUnits {
	short code;
	string name;
	int year;
	int edu;
};

void showData(SubUnits* Unit, int amount) {
	system("cls");
	cout << "#\t" << "Code\t" << "Name\t" << "Education\t" << "Year" << endl;
	cout << "==========================================================" << endl;
	for (int i = 0; i < amount; i++) {
		cout << i + 1 << "\t" << Unit[i].code << "\t" << Unit[i].name << "\t" << Unit[i].edu << "\t" << Unit[i].year << endl;
	}
}

int main() {
	int amountOfUnits;
	short coden;
	cout << "Code for sort:";
	cin >> coden;
	cout << "Amount: ";
	cin >> amountOfUnits;
	SubUnits* Unit = new SubUnits[amountOfUnits];
	for (int i = 0; i < amountOfUnits; i++) {
		cout << i + 1 << " unit\n";
		cout << "Code: ";
		cin >> Unit[i].code;
		cout << "Name: ";
		cin.get();
		getline(cin, Unit[i].name);
		cout << "Birth year: ";
		cin >> Unit[i].year;
		cout << "Education: ";
		cin >> Unit[i].edu;
	}

	for (int i = 0; i < amountOfUnits - 1; i++) {
		for (int j = 0; j < amountOfUnits - i - 1; j++) {
			if (Unit[j].code > Unit[j + 1].code) {
				swap(Unit[j].code, Unit[j + 1].code);
				swap(Unit[j].name, Unit[j + 1].name);
				swap(Unit[j].year, Unit[j + 1].year);
				swap(Unit[j].edu, Unit[j + 1].edu);
			}
		}
	}
	for (int i = 0; i < amountOfUnits - 1; i++) {
		for (int j = 0; j < amountOfUnits - i - 1; j++) {
			if (Unit[j].code == coden && Unit[j + 1].code == coden) {
				if (Unit[j].edu < Unit[j + 1].edu) {
					swap(Unit[j].code, Unit[j + 1].code);
					swap(Unit[j].name, Unit[j + 1].name);
					swap(Unit[j].year, Unit[j + 1].year);
					swap(Unit[j].edu, Unit[j + 1].edu);
				}
			}
		}
	}
	for (int i = 0; i < amountOfUnits - 1; i++) {
		for (int j = 0; j < amountOfUnits - i - 1; j++) {
			if (Unit[j].code == coden && Unit[j + 1].code == coden) {
				if (Unit[j].year < Unit[j + 1].year) {
					swap(Unit[j].code, Unit[j + 1].code);
					swap(Unit[j].name, Unit[j + 1].name);
					swap(Unit[j].year, Unit[j + 1].year);
					swap(Unit[j].edu, Unit[j + 1].edu);
				}
			}
		}
	}
	showData(Unit, amountOfUnits);
}