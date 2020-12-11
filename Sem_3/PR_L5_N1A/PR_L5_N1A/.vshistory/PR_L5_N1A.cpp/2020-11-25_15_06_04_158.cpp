#include <iostream>

using namespace std;

double distance;

class Vehicle {
protected:
	double perKM, perKG, time, maxSpeed;
	void SetMaxSpeed(int speed) {
		maxSpeed = speed;
	}
	void SetPerKM() {
		perKM = 1 / maxSpeed;
	}
	void SetPerKG() {
	}
	void SetTime() {
		time = distance / maxSpeed;
	}
};

class Car : public Vehicle {
	double literPerKM, pricePerLiter;

};

class Bicycle : public Vehicle {

};

class Carriage : public Vehicle {

};

int main() {

}