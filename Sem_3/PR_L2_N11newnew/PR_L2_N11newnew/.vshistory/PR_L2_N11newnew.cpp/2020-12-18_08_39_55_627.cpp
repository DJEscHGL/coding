#include <iostream>
#include <Windows.h>
#include <fstream>
#include <locale>
#include <time.h>

using namespace std;

int** buff;
ifstream input("input.txt");
ofstream output("output.txt");

class Matrix {
public:
	int n, m, p;
	int** matr, ** minor;
	//Конструктор
	Matrix() {
		//cout << "Размерность матрицы:\nn = ";
		input >> n;
		//cout << "m = ";
		input >> m;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matr[i][j] = rand() % 100;
			}
		}
		//cout << "Порядок миноров:";
		input >> p;
		buff = new int* [2];
		for (int i = 0; i < 2; i++)
			buff[i] = new int[p];
		//cout << "Номера столбцов\n";
		for (int i = 0; i < p; i++)
			input >> buff[0][i];
		//cout << "Номера строк\n";
		for (int i = 0; i < p; i++)
			input >> buff[1][i];
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
	//Конструктор копирования
	Matrix(const Matrix& obj) {
		n = obj.n;
		m = obj.m;
		p = obj.p;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[m];
		minor = new int* [p];
		for (int i = 0; i < p; i++)
			minor[i] = new int[p];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matr[i][j] = obj.matr[i][j];
			}
		}
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor[i][j] = obj.minor[i][j];
			}
		}
	}
	//Конструктор для операций
	Matrix(const Matrix& obj, bool ch) {
		p = obj.p;
		minor = new int* [p];
		for (int i = 0; i < p; i++)
			minor[i] = new int[p];
		matr = NULL;
		m = NULL;
		n = NULL;
	}
	//Сложение миноров
	void Summig(Matrix min1, Matrix min2) {
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor[i][j] = min1.minor[i][j] + min2.minor[i][j];
			}
		}
	}
	//Вычитание миноров
	void Subtraction(Matrix min1, Matrix min2) {
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor[i][j] = min1.minor[i][j] - min2.minor[i][j];
			}
		}
	}
	//Умножение миноров
	void Multiplication(Matrix min1, Matrix min2) {
		int buffer = 0;
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				for (int q = 0; q < p; q++) {
					buffer += min1.minor[i][q] * min2.minor[q][j];
				}
				minor[i][j] = buffer;
			}
		}
	}
	//Вывод матрицы и минора
	void Output() {
		cout << "Матрица\n";
		output << "Матрица\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << matr[i][j] << "\t";
				output << matr[i][j] << "\t";
			}
			cout << endl;
			output << endl;
		}
		output << "Минор\n";
		cout << "Минор\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				output << minor[i][j] << "\t";
				cout << minor[i][j] << "\t";
			}
			output << endl;
			cout << endl;
		}
	}
	//Вывод Матриы
	void OutMatr() {
		cout << "Матрица\n";
		output << "Матрица\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << matr[i][j] << "\t";
				output << matr[i][j] << "\t";
			}
			cout << endl;
			output << endl;
		}
	}
	//Вывод Минора
	void OutMin() {
		output << "Минор\n";
		cout << "Минор\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				output << minor[i][j] << "\t";
				cout << minor[i][j] << "\t";
			}
			output << endl;
			cout << endl;
		}
	}
	//Изменение элемента минора
	void ChangeMinor(int neww, int i, int j) {
		minor[i][j] = neww;
	}
	//Геттер размера минора
	int GetP() {
		return p;
	}
	//Геттер элемента минора
	int GetElement(int i, int j) {
		return minor[i][j];
	}
	//Перегрузка операции присваивания
	Matrix operator= (Matrix obj) {
		p = obj.p;
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor[i][j] = obj.minor[i][j];
			}
		}
		return *this;
	}
};

//Перегрузка операции сложения
Matrix operator+ (Matrix min1, Matrix min2) {
	Matrix result(min1, true);
	result.Summig(min1, min2);
	return result;
}

//Перегрузка операции вычитания
Matrix operator- (Matrix min1, Matrix min2) {
	Matrix result(min1, true);
	result.Subtraction(min1, min2);
	return result;
}

//Перегрузка операции умножения
Matrix operator* (Matrix min1, Matrix min2) {
	Matrix result(min1, true);
	result.Multiplication(min1, min2);
	return result;
}

//Основное условие
void Task(Matrix* obj) {
	int neww, m, p, c;
	cout << "Минор какой матрицы изменить: ";
	cin >> m;
	cout << "На какое число умножить минор:";
	cin >> c;
	obj[m].Output();
	p = obj[m].GetP();
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			neww = obj[m].GetElement(i, j) * c;
			obj[m].ChangeMinor(neww, i, j);
		}
	}
	output << "Новый минор данной матрицы:\n";
	cout << "Новый минор данной матрицы:\n";
	obj[m].OutMin();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(NULL));
	int k;
	//cout << "Введите количество матриц: ";
	input >> k;
	Matrix* obj = new Matrix[k];
	Matrix copyOf1(obj[0]);
	Matrix result(obj[0], true);
	bool flag = true;
	bool flag1 = true;
	if (input.is_open())
	{
		cout << "Файл input.txt открытый" << endl;
	}
	else
		input.open("input.txt");
	if (output.is_open())
	{
		cout << "Файл output.txt открытый" << endl;
	}
	//Меню
	while (flag) {
		system("cls");
		int choice;
		cout << "Введите номер нужного пункта\n0.Выход\n1.Вывод матриц и миноров\n2.Проверка перегрузок операторов.\n3.Основное условие" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			for (int i = 0; i < k; i++) {
				output << "/////////////////////////////\n";
				cout << "/////////////////////////////\n";
				obj[i].Output();
			}
			system("pause");
			break;
		case 2:
			while (flag1) {
				system("cls");
				int choice1;
				cout << "Введите номер нужного пункта\n0.Выход\n1.Суммирование.\n2.Вычитание.\n3.Умножение" << endl;
				cin >> choice1;
				switch (choice1) {
				case 0:
					flag1 = false;
					break;
				case 1:
					system("cls");
					result = obj[0] + copyOf1;
					copyOf1.OutMatr();
					copyOf1.OutMin();
					output << "Результат:\n";
					cout << "Результат:\n";
					result.OutMin();
					system("pause");
					break;
				case 2:
					system("cls");
					result = obj[0] - copyOf1;
					copyOf1.OutMatr();
					copyOf1.OutMin();
					output << "Результат:\n";
					cout << "Результат:\n";
					result.OutMin();
					system("pause");
					break;
				case 3:
					system("cls");
					result = obj[0] * copyOf1;
					copyOf1.OutMatr();
					copyOf1.OutMin();
					output << "Результат:\n";
					cout << "Результат:\n";
					result.OutMin();
					system("pause");
					break;
				}
			}
			break;
		case 3:
			system("cls");
			Task(obj);
			system("pause");
			break;
		default:
			system("cls");
			cout << "Введён неверный вариант";
			system("pause");
			break;
		}
	}
	input.close();
	output.close();
}