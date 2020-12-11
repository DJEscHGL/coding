#include <iostream>
#include <time.h>

using namespace std;

class Vehicle {
public:
	int id, perMan;
	double perKm, maxSpeed;
	void setId(int i) {
		id = i + 1;
	}
	void setMaxSpeed() {
		cout << "Максимальная скорость: ";
		cin >> maxSpeed;
	}
	void show() {
		cout << id << "\t" << maxSpeed << "\t\t" << perKm << endl;
	}
	virtual void costOfKM() = 0;
};

class Car : public Vehicle {
public:
};

class Bicycle : public Vehicle {
public:

};

class Carriage : public Vehicle {
public:

};

void Calculate(Vehicle** transport, int i, double distance, double weight) {
}

int main() {
	srand((unsigned int)time(NULL));
	setlocale(0, "");
	double distance, weight;
	int numOfMan;
	cout << "Введите длину маршрута: ";
	cin >> distance;
	cout << "Введите перевозимый вес: ";
	cin >> weight;
	cout << "Введите количество перевозимых людей: ";
	cin >> numOfMan;
	auto transport = new Vehicle * [9];
	bool flag = true;
	int choice2;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Вывод всего транспорта\n2.Машины\n3.Велосипеды\n4.Повозки\n";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			cout << "ID" << "\t" << "MaxSpeed" << "\t" << "PerKM" << "\t" << "PerKG" << endl;
			for (int i = 0; i < 9; i++) {
				transport[i]->show();
			}
			system("pause");
			break;
		case 2:
			cout << "Введите id машины: ";
			cin >> choice2;
			Calculate(transport, choice2 - 1, distance, weight);
			break;
		}
	}
}