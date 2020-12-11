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

int main() {
	setlocale(0, "");
	double distance;
	cout << "Расстояние до точки прибытия: ";
	cin >> distance;
	bool flag = true;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Машины\n2.Велосипеды\n3.Повозки";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		}
	}
}