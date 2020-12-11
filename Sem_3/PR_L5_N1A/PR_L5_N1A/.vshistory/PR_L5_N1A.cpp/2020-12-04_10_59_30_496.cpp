#include <iostream>

using namespace std;

class Vehicle {
protected:
	int id, perMan;
	double perKm, perKg, maxSpeed;
	virtual void setId() = 0;
	virtual void setMaxSped() = 0;
	virtual void setPerKm() = 0;
	virtual void setPerMan() = 0;
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
};

class Car : public Vehicle {
protected:
	double coefficient; // от 0.0 до 1.0
	void setCoefficient(double coef) {
		coefficient = coef;
	}
	virtual void setMaxSpeed() {
		cin >> maxSpeed;
	}
	virtual void setPerKm() {
		perKm = maxSpeed * 0.1 * coefficient;
	}
	virtual void setPerMan(int numOfMan) {
		perMan = ceil(numOfMan / 4); // округление в большую сторону
	}
	virtual void setPerKg(double weight) {
		perKg = weight * 4;
	}
};

class Bicycle : public Vehicle {
protected:
	int type; // 1 или 2
	virtual void setMaxSpeed() {
		cin >> maxSpeed;
	}
	virtual void setPerKm() {
		perKm = maxSpeed * 0.1 * 0.6;
	}
	virtual void setPerMan(int numOfMan) {
		perMan = ceil(numOfMan / type);
	}
	virtual void setPerKg(double weight) {
		perKg = weight * 6;
	}
};

class Carriage : public Vehicle {
protected:
	virtual void setMaxSpeed() {
		cin >> maxSpeed;
	}
	virtual void setPerKm() {
		perKm = maxSpeed * 0.1 * 0.8;
	}
	virtual void setPerMan(int numOfMan) {
		perMan = ceil(numOfMan / 6);
	}
	virtual void setPerKg(double weight) {
		perKg = weight * 8;
	}
};

void Calculate() {

}

int main() {
	setlocale(0, "");
	double distance, weight;
	int numOfMan;
	/* Тут должен быть массив и заполненние */
	bool flag = true;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Машины\n2.Велосипеды\n3.Повозки\n";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		}
	}
}