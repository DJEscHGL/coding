#include <iostream>
#include <time.h>
#include <cmath>


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
	void output() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matr[i][j] << "\t";
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
	void Subtract() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matr[i][j] - matr[i][j] << "\t";
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
	void Norma() {
		int norma = 0, buff = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				buff += abs(matr[i][j]);
			}
			if (norma <= buff)
				norma = buff;
			buff = 0;
		}
		cout << norma << endl;
	}

};

void Func(Matrix* obj) {
	int i;
	cin >> i;
	obj[i].Multiplication();
}

int main() {
	srand((unsigned int)time(NULL));
	int n, k;
	cout << "Количество матриц: ";
	cin >> n;
	Matrix* obj = new Matrix[n];
	bool flag = true;
	while (flag) {
		int choice;
		cout << "Введите номер нужного пункта\n0. Выход.";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
		case 2:

		default:
			system("cls");
			cout << "Введён неверный вариант";
			break;
		}
	}
}
