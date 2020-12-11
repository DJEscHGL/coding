#include <iostream>
#include <fstream>

using namespace std;
ifstream input("input.txt");

class Vehicle {
public:
	int id, perMan;
	double perKm, perKg, maxSpeed;
	Vehicle(int i) {
		id = i + 1;
	}
	virtual void setMaxSped() = 0;
	virtual void setPerKm() = 0;
	virtual void setPerMan(int numOfMan) = 0;
	virtual void setPerKg() = 0;
	int getId() {
		return id;
	}
	double getMaxSpeed() {
		return maxSpeed;
	}
	double getPerKm() {
		return perKm;
	}
	double getPerKg() {
		return perKg;
	}
	void show() {
		cout << id << "\t" << maxSpeed << "\t" << perKm << "\t" << perKg;
	}
};

class Car : public Vehicle {
public:
	double coefficient; // от 0.0 до 1.0
	virtual void setMaxSpeed() {
		input >> maxSpeed;
	}
	virtual void setPerKm() {
		perKm = maxSpeed * 0.1 * coefficient;
	}
	virtual void setPerMan(int numOfMan) {
		perMan = ceil(numOfMan / 4); // округление в большую сторону
	}
	virtual void setPerKg() {
		perKg = maxSpeed * 0.01 + 2;
	}
};

class Bicycle : public Vehicle {
public:
	virtual void setMaxSpeed() {
		input >> maxSpeed;
	}
	virtual void setPerKm() {
		perKm = maxSpeed * 0.1 * 0.6;
	}
	virtual void setPerMan(int numOfMan) {
		perMan = ceil(numOfMan / type);
	}
	virtual void setPerKg() {
		perKg = maxSpeed * 0.01 + 2;
	}
};

class Carriage : public Vehicle {
public:
	virtual void setMaxSpeed() {
		input >> maxSpeed;
	}
	virtual void setPerKm() {
		perKm = maxSpeed * 0.1 * 0.8;
	}
	virtual void setPerMan(int numOfMan) {
		perMan = ceil(numOfMan / 6);
	}
	virtual void setPerKg() {
		perKg = maxSpeed * 0.01 + 2;
	}
};

void Calculate() {

}

int main() {
	setlocale(0, "");
	double distance, weight;
	int numOfMan;
	cout << "Введите длину маршрута: ";
	cin >> distance;
	cout << "Введите перевозимый вес: ";
	cin >> weight;
	cout << "Введите количество перевозимых людей: ";
	cin >> numOfMan;
	Car n1;
	Vehicle* transport[9] = {};
	bool flag = true;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Вывод всего транспорта\n2.Машины\n3.Велосипеды\n4.Повозки";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:

			break;
		}
	}
	input.close();
}