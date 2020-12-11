#include <iostream>
#include <time.h>
#include <cmath>


using namespace std;

class Matrix {
private:
	int n;
	int** matr;
public:
	//Конструктор
	Matrix() {
		cout << "Размерность матрицы: ";
		cin >> n;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = rand() % 100;
			}
		}
	}
	//Конструктор копирования
	Matrix(const Matrix& obj) {
		n = obj.n;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = obj.matr[i][j];
			}
		}
	}
	//Конструктор пустой матрицы(для операций)
	Matrix(const Matrix& obj, bool ch) {
		n = obj.n;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[n];
	}
	//Деструктор
	~Matrix() {
		for (int i = 0; i < n; i++)
			delete[] matr[i];
		delete[] matr;
	}
	//Вывод матрицы
	void output() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	//Сложение матриц
	void Summig(Matrix ob1, Matrix ob2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = ob1.matr[i][j] + ob2.matr[i][j];
			}
		}
	}
	//Вычитание миноров
	void Subtraction(Matrix ob1, Matrix ob2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matr[i][j] = ob1.matr[i][j] - ob2.matr[i][j];
			}
		}
	}
	//Умножение миноров
	void Multiplication(Matrix ob1, Matrix ob2) {
		int buffer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int q = 0; q < n; q++) {
					buffer += ob1.matr[i][q] * ob2.matr[q][j];
				}
				matr[i][j] = buffer;
			}
		}
	}
	//Норма матрицы
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
