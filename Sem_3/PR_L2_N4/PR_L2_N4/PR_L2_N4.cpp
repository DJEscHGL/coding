#include <iostream>
#include <time.h>

using namespace std;

class Matrix {
private:
	int n;
	int** matr;
public:
	~Matrix() {
		for (int i = 0; i < n; i++)
			delete[] matr[i];
		delete[] matr;
	}
	void createMatrix(int nn) {
		n = nn;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = rand() % 100;
			}
		}
	}
	void output() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Add(Matrix *obj) {
		int a, b;
		cout << "Какие матрицы сложить(" << 0 << " - " << n << "): ";
		cin >> a, b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << obj[a].matr[i][j] + obj[b].matr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Add() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matr[i][j] + matr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Subtract(Matrix* obj) {
		int a, b;
		cout << "Какие матрицы вычесть(" << 0 << " - " << n << "): ";
		cin >> a, b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << obj[a].matr[i][j] - obj[b].matr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Subtract() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matr[i][j] - matr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Multiplication(Matrix* obj) {
		int a, b;
		cout << "Какие матрицы перемнодить(" << 0 << " - " << n << "): ";
		cin >> a, b;
		int buff = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int q = 0; q < n; q++) {
					buff += obj[a].matr[i][q] * obj[b].matr[q][j];
				}
				cout << buff << "\t";
			}
			cout << endl;
		}
	}
	void Multiplication() {
		int buff = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int q = 0; q < n; q++) {
					buff += matr[i][q] * matr[q][j];
				}
				cout << buff << "\t";
			}
			cout << endl;
		}
	}
};

int main() {
	srand(time(NULL));
	int n, k;
	cout << "Количество матриц: ";
	cin >> n;
	cout << "Порядок матриц: ";
	cin >> k;
	Matrix *obj = new Matrix[n];
	for (int i = 0; i < n; i++)
		obj[i].createMatrix(k);
}