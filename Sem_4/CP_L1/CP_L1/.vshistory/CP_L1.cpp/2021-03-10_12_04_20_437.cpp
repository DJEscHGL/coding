#include <iostream>
#include <new>
#include <time.h>

using namespace std;

int num, tim;

class Vector {
public:
	int n;
	double* points;
	Vector() {
		cout << "Введите размерность веткора:\n";
		cin >> n;
		points = new double[n];
		cout << "Введите через пробел координаты вектора:\n";
		for (int i = 0; i < n; i++) {
			cin >> points[i];
		}
	}
	Vector(double* arr, int nn) {
		n = nn;
		for (int i = 0; i < n; i++) {
			points[i] = arr[i];
		}
	}
};

istream& operator>> (istream& in, Vector* vect) {
	double* arr1;
	int size1;
	size1 = 2 + rand() % 5;
	arr1 = new double[size1];
	for (int i = 0; i < size1; i++) {
		arr1[i] = (double)(rand()) / RAND_MAX * (20) - 10;
	}
	new (vect + tim) Vector(arr1, size1);
	delete arr1;
	return in;
}

ostream& operator<< (ostream& out, Vector& vect) {
	out << "{ ";
	for (int i = 0; i < vect.n; i++) {
		out << vect.points[i] << "; ";
	}
	out << "}\n";
	return out;
}

void Test(Vector* vectors, int num) {
}

int main() {
	srand(time(NULL));
	setlocale(0, "");
	num = 6;
	Vector* vectors;
	vectors = static_cast<Vector*>(operator new[](num * sizeof(Vector)));
	for (tim = 0; tim < 3; tim++) {
		new (vectors + tim) Vector();
	}
	for (tim; tim < 3; tim++) {
		cin >> vectors;
	}
	Test(vectors, num);
	for (tim = 0; tim < num; tim++) {
		cout << vectors[tim];
	}
}