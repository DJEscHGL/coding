#include <iostream>

using namespace std;

class Matrix {
private:
	int n, m, p;
	int** matr, ** minor, **buff;
public:
	//Конструктор для основного условия
	Matrix() {
		cout << "Размерность матрицы:\nn = ";
		cin >> n;
		cout << "m = ";
		cin >> m;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matr[i][j] = rand() % 100;
			}
		}
		cout << "Порядок миноров:";
		cin >> p;
		buff = new int* [2];
		for (int i = 0; i < 2; i++)
			buff[i] = new int[p];
		cout << "Номера столбцов\n";
		for (int i = 0; i < p; i++)
			cin >> buff[0][i];
		cout << "Номера строк\n";
		for (int i = 0; i < p; i++)
			cin >> buff[1][i];
		minor = new int* [p];
		for (int i = 0; i < p; i++)
			minor[i] = new int[p];
		int temp2 = 0, temp1 = 0;
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor[i][j] = matr[buff[1][temp2]][buff[0][temp1]];
				temp1++;
			}
			temp1 = 0;
			temp2++;
		}
	}
	//Конструктор минора для операций
	Matrix(const Matrix& min) {
		p = min.p;
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor[i][j] = min.minor[i][j];
			}
		}
		matr = NULL;
		buff = NULL;
	}
	//Геттер элемента минора
	int GetElement(int i, int j) {
		return minor[i][j];
	}
	//Сеттер элемента матрицы
	void SetElement(int i, int j) {
		minor
	}
	//Геттер порядка минора
	int GetP() {
		return p;
	}
	//Перегрузка операции присвоения
	Matrix& operator= (const Matrix& min) {
		for (int i = 0; i < min.p; i++) {
			for (int j = 0; j < min.p; j++) {
				minor1[i][j] = min.minor1[i][j];
			}
		}
		return *this;
	}
};

//Перегрузка операции сложения
Matrix operator+ (Matrix min1, Matrix min2) {
	Matrix result(min1);
	if (min1.GetP() == min2.GetP()) {
		for (int i = 0; i < result.GetP(); i++) {
			for (int j = 0; j < result.GetP(); j++) {

			}
		}
	}
	return result;
}

int main() {

}