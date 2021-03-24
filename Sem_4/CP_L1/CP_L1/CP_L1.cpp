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
	Vector(int nn) {
		n = nn;
		points = new double[n];
	}
	Vector(double* arr, int nn) {
		n = nn;
		points = new double[n];
		for (int i = 0; i < n; i++) {
			points[i] = arr[i];
		}
	}
	Vector(const Vector& vect) {
		n = vect.n;
		points = new double[n];
		for (int i = 0; i < n; i++) {
			points[i] = vect.points[i];
		}
	}
	~Vector() {
		delete[] points;
	}

	double Module() {
		double temp = 0;
		for (int i = 0; i < n; i++) {
			temp += (points[i] * points[i]);
		}
		return sqrt(temp);
	}

	void ScalarMult(Vector v1, Vector v2) {
		double temp = 0;
		for (int i = 0; i < v1.n; i++) {
			temp += (v1.points[i] * v2.points[i]);
		}
		cout << "Произведение двух векторов = " << temp << endl;
	}

	void VectorMult() {

	}

	Vector operator= (Vector obj) {
		n = obj.n;
		for (int i = 0; i < n; i++) {
			points[i] = obj.points[i];
		}
		return *this;
	}
	Vector operator+ (Vector obj) {
		for (int i = 0; i < n; i++) {
			points[i] += obj.points[i];
		}
		return *this;
	}
	Vector operator- (Vector obj) {
		for (int i = 0; i < n; i++) {
			points[i] -= obj.points[i];
		}
		return *this;
	}

	Vector& operator++() {
		for (int i = 0; i < n; i++) {
			points[i]++;
		}
		return *this;
	}

	Vector& operator--() {
		for (int i = 0; i < n; i++) {
			points[i]--;
		}
		return *this;
	}

	Vector operator++ (int) {
		Vector obj(*this);
		++(*this);
		return obj;
	}

	Vector operator-- (int) {
		Vector obj(*this);
		--(*this);
		return obj;
	}

	Vector operator* (double a) {
		for (int i = 0; i < n; i++) {
			points[i] *= a;
		}
		return *this;
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
	for (tim; tim < num; tim++) {
		cin >> vectors;
	}
	Test(vectors, num);
	for (tim = 0; tim < num; tim++) {
		cout << vectors[tim];
	}
}