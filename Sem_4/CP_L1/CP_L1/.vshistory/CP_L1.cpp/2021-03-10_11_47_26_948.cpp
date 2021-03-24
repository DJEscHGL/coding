#include <iostream>
#include <new>

using namespace std;

int num;

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
		points = arr;
	}
};

istream& operator>> (istream& in, Vector* vect) {
	double *arr1, *arr2, *arr3;
	int size1, size2, size3;
	size1 = 2 + rand() % 7;
	size2 = 2 + rand() % 8;
	size3 = 2 + rand() % 9;
	arr1 = new double[size1];
	arr2 = new double[size2];
	arr3 = new double[size3];
	for (int i = 0; i < size1; i++) {
		arr1[i] = (double)(-10 + rand() % 10);
	}
	for (int i = 3; i < num; i++) {
		new (vect + i) Vector();
	}
	return in;
}

ostream& operator<< (ostream& out, Vector& vect) {
	out << "{ ";
	for (int i = 0; i < vect.n; i++) {
		out << vect.points[i] << "; ";
	}
	out << "}";
	return out;
}

void Test(Vector* vectors, int num) {
}

int main() {
	setlocale(0, "");
	int i;
	num = 6;
	Vector* vectors;
	vectors = static_cast<Vector*>(operator new[](num * sizeof(Vector)));
	for (i = 0; i < 3; i++) {
		new (vectors + i) Vector();
	}
	for (i; i < 6; i++) {
		cin >> vectors;
	}
	Test(vectors, num);
}