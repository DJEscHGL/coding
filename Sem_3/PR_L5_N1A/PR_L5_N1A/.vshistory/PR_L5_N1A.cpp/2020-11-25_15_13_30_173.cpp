#include <iostream>

using namespace std;

class Vehicle {
protected:
	double perKM, perKG, time, maxSpeed, maxWeight;
	void SetMaxSpeed(int speed) {
		maxSpeed = speed;
	}
	void SetPerKM() {
		perKM = 1 / maxSpeed;
	}
	void SetPerKG() {
	}
	void SetTime(double distance) {
		time = distance / maxSpeed;
	}
};

class Car : public Vehicle {
protected:
	double literPerKM, pricePerLiter;
public:
};

class Bicycle : public Vehicle {

};

class Carriage : public Vehicle {

};

void menu() {
	double distance;
	cout << "Расстояние до точки прибытия: ";
	cin >> distance;
	Car Car;
	Bicycle bicycle;
	Carriage carriage;
	bool flag = true;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Машиной\n2.Велосипедом\n3.Повозкой";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		};
}

int main() {
	setlocale(0, "");
	menu();
}