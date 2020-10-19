#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

class Matrix {
private:
	int n, m, p;
	int** matr, **minor;
public:
	Matrix() {
		cout << "Размерность матрицы:\nn = ";
		cin >> n;
		cout << "m = ";
		cin >> m;
		int buff;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matr[i][j] = rand() % 100;
			}
		}
		if (n < m)
			buff = n;
		else
			buff = m;
		p = rand() % (buff - 1) + 2;
		minor = new int* [p];
		for (int i = 0; i < p; i++)
			minor[i] = new int[p];
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor[i][j] = matr[n - p + i][m - p + j];
			}
		}
	}
	Matrix(const Matrix& obj) {
		n = obj.n;
		m = obj.m;
		p = obj.p;
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matr[i][j] = obj.matr[i][j];
			}
		}
		minor = new int* [p];
		for (int i = 0; i < p; i++)
			minor[i] = new int[p];
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor[i][j] = obj.minor[i][j];
			}
		}
	}
	~Matrix() {
		for (int i = 0; i < n; i++)
			delete[] matr[i];
		delete[] matr;
		for (int i = 0; i < p; i++)
			delete[] minor[i];
		delete[] minor;
	}
	void Output() {
		cout << "Матрица\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << matr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "Минор\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << minor[i][j] << "\t";
			}
			cout << endl;
		}	
	}
	void OutMinor(Matrix* obj, int a) {
		cout << "Минор\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << obj[a].minor[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Add(Matrix* obj, int q) {
		int a, b;
		cout << "\nСуммировать миноры, можно только одного порядка, вот список миноров и порядок\n";
		for (int i = 0; i < q; i++)
			cout << i << "\t";
		cout << endl;
		for (int i = 0; i < q; i++)
			cout << obj[i].p << "\t";
		cout << "\nКакие миноры сложить:\n";
		cin >> a;
		cin >> b;
		if (obj[a].p != obj[b].p) {
			cout << "Неправильный ввод..";
			return;
		}
		system("cls");
		cout << "Введённые миноры\n";
		OutMinor(obj, a);
		cout << endl;
		OutMinor(obj, b);
		cout << "\nРезультат:\n";
		int t = obj[a].p;
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < t; j++) {
				cout << obj[a].minor[i][j] + obj[b].minor[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Add() {
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << minor[i][j] + minor[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Subtract(Matrix* obj, int q) {
		int a, b;
		system("cls");
		cout << "Вычитать миноры, можно только одного порядка, вот список миноров и порядок\n";
		for (int i = 0; i < q; i++)
			cout << i << "\t";
		cout << endl;
		for (int i = 0; i < q; i++)
			cout << obj[i].p << "\t";
		cout << "\nКакие миноры вычесть:\n";
		cin >> a;
		cin >> b;
		if (obj[a].p != obj[b].p) {
			cout << "Неправильный ввод..";
			return;
		}
		system("cls");
		cout << "Введённые миноры\n";
		OutMinor(obj, a);
		cout << endl;
		OutMinor(obj, b);
		cout << "\nРезультат:\n";
		int t = obj[a].p;
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < t; j++) {
				cout << obj[a].minor[i][j] - obj[b].minor[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Subtract() {
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << minor[i][j] - minor[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Multiplication(Matrix* obj, int q) {
		int a, b;
		system("cls");
		cout << "Перемножать миноры, можно только одного порядка, вот список миноров и порядок\n";
		for (int i = 0; i < q; i++)
			cout << i << "\t";
		cout << endl;
		for (int i = 0; i < q; i++)
			cout << obj[i].p << "\t";
		cout << "\nКакие миноры перемножить:\n";
		cin >> a;
		cin >> b;
		if (obj[a].p != obj[b].p) {
			cout << "Неправильный ввод..";
			return;
		}
		system("cls");
		cout << "Введённые миноры\n";
		OutMinor(obj, a);
		cout << endl;
		OutMinor(obj, b);
		cout << "\nРезультат:\n";
		int t = obj[a].p;
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
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				for (int q = 0; q < p; q++) {
					buff += minor[i][q] * minor[q][j];
				}
				cout << buff << "\t";
			}
			cout << endl;
		}
	}
	void ChangeMinor(int neww, int i, int j) {
		minor[i][j] = neww;
	}
	int GetP() {
		return p;
	}
	int GetElement(int i, int j) {
		return minor[i][j];
	}
};

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
	cout << "Новый минор данной матрицы:\n";
	obj[m].OutMinor(obj, m);
}

int main() {
	setlocale(0, "");
	srand((unsigned int)time(NULL));
	int k;
	cout << "Введите количество матриц: ";
	cin >> k;
	Matrix* obj = new Matrix[k];
	bool flag = true;
	bool flag1 = true;
	int w = rand() % k;
	Matrix copyOfW(obj[w]);
	int random = rand() % k;
	while (flag) {
		system("cls");
		int choice;
		cout << "Введите номер нужного пункта\n0.Выход\n1.Вывод матриц и миноров\n2.Проверка перегрузок.\n3.Конструктор копирования\n4.Основное условие." << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			for (int i = 0; i < k; i++)
				obj[i].Output();
			system("pause");
			break;
		case 2:
			while (flag1) {
				system("cls");
				int choice1;
				cout << "Введите номер нужного пункта\n0.Выход\n1.Перегрузка суммирования.\n2.Перегрузка вычитания.\n3.Перегрузка умножения" << endl;
				cin >> choice1;
				switch (choice1) {
				case 0:
					flag1 = false;
					break;
				case 1:
					obj[0].Add(obj, k);
					cout << "Сумма минора "<< random << " с самим собой\n";
					obj[random].Add();
					system("pause");
					break;
				case 2:
					obj[0].Subtract(obj, k);
					cout << "Разность минора " << random << " с самим собой\n";
					obj[random].Subtract();
					system("pause");
					break;
				case 3:
					obj[0].Multiplication(obj, k);
					cout << "Произведение минора " << random << " с самим собой\n";
					obj[random].Multiplication();
					system("pause");
					break;
				}
			}
			break;
		case 3:
			system("cls");
			cout << "Копия матрицы " << w;
			cout << "\nВывод скопированной матрицы и минора\n";
			copyOfW.Output();
			system("pause");
			break;
		case 4:
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
	for (int i = 0; i < k; i++)
		obj[i].~Matrix();
}