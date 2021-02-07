#include <iostream>
#include <locale>
#include <Windows.h>
#include <string>

using namespace std;

class Man {
public:
	string name, gender;
	int age;
	double weight;
	void SetGender(string newgender) {
		gender = newgender;
	}
	void SetName(string newname) {
		name = newname;
	}
	void SetAge(int newage) {
		age = newage;
	}
	void SetWeight(double newweight) {
		weight = newweight;
	}
};

class Student : public Man {
public:
	int year;
	Student(int num) {
		year = num;
	}
	Student operator++(int){
		year++;
		return *this;
	}
	Student operator--(int) {
		year++;
		return *this;
	}
	void SetYear(int newyear) {
		year = newyear;
	}
	void InDecYear(Student person) {
		int ch;
		cout << "1. Увеличить на 1\n2. Уменьшить на 1";
		cin >> ch;
		if (ch == 1)
			person++;
		else
			person--;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name, gender;
	int age, year;
	double weight;
	cout << "Введите имя:\n";
	getline(cin, name);
	cin.get();
	cout << "Введите пол:\n";
	getline(cin, gender);
	cin.get();
	cout << "Введите возраст:\n";
	cin >> age;
	cout << "Введите вес:\n";
	cin >> weight;
	cout << "Введите год обучения:\n";
	cin >> year;
	Student fst(year);
	fst.SetGender(gender);
	fst.SetAge(age);
	fst.SetName(name);
	fst.SetWeight(weight);
	bool flag = true;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Изменить имя\n2.Изменить возраст\n3.Изменить вес\n4.Изменить год обучения\n5.Увеличть/уменьшить на 1 год обучения\n";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			cout << "Введите имя:\n";
			getline(cin, name);
			cin.get();
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Введите возраст:\n";
			cin >> age;
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Введите вес:\n";
			cin >> weight;
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "Введите год обучения:\n";
			cin >> year;
			system("pause");
			break;
		case 5:
			system("cls");
			fst.InDecYear(fst);
			system("pause");
			break;
		}
	}
}