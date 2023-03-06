#include <iostream>
#include "vector.h"

using namespace std;

void Vector::setSize(int n) {
	this->size = n;
}

void Vector::getSize() {
	cout << "Размерность вектора " << this->size << endl;
}

void Vector::generateVector() {
	srand(time(NULL));
	for (int i = 0; i < this->size; i++) {
		this->array[i] = -50 + rand() % 50;
	}
}