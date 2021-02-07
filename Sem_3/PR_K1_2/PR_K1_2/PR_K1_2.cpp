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
	void Out() {
		cout << name << " " << gender << " " << age << " " << weight << " " << year << endl;
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
		cout << "0.Выход\n1.Вывод всех данных\n2.Изменить имя\n3.Изменить возраст\n4.Изменить вес\n5.Изменить год обучения\n6.Увеличть на 1 год обучения\n7.Уменьшить на 1 год обучения\n";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			fst.Out();
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Введите имя:\n";
			getline(cin, name);
			cin.get();
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Введите возраст:\n";
			cin >> age;
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "Введите вес:\n";
			cin >> weight;
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "Введите год обучения:\n";
			cin >> year;
			system("pause");
			break;
		case 6:
			system("cls");
			fst++;
			system("pause");
			break;
		case 7:
			system("cls");
			fst--;
			system("pause");
			break;
		}
	}
}