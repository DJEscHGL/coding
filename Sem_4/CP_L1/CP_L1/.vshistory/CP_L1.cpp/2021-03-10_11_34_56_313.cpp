#include <iostream>
#include <new>

using namespace std;

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

istream& operator>> (istream& in, Vector& vect) {

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
	int num;
	num = 6;
	Vector* vectors;
	vectors = static_cast<Vector*>(operator new[](num * sizeof(Vector)));
	for (int i = 0; i < 3; i++) {
		new (vectors + i) Vector();
	}
	for (int i = 0; i < 2; i++) {
		cin >> new (vectors + i) Vector();
	}
	Test(vectors, num);
}