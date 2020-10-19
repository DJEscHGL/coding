#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

class Matrix {
private:
	int n, m, p;
	int** matr, ** minor1, ** minor2, ** buff;
public:
	Matrix() {
		minor2 = NULL;
		buff = NULL;
		cout << "Размерность матрицы:\nn = ";
		cin >> n;
		cout << "m = ";
		cin >> m;
		int buffe; 
		matr = new int* [n];
		for (int i = 0; i < n; i++)
			matr[i] = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matr[i][j] = rand() % 100;
			}
		}
		if (n < m)
			buffe = n;
		else
			buffe = m;
		p = rand() % (buffe - 1) + 2;
		minor1 = new int* [p];
		for (int i = 0; i < p; i++)
			minor1[i] = new int[p];
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor1[i][j] = matr[n - p + i][m - p + j];
			}
		}
	}
	Matrix(bool zero) {
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
		buff = new int* [4];
		for (int i = 0; i < 4; i++)
			buff[i] = new int[p];
		cout << "Номера столбцов\n";
		for (int i = 0; i < p; i++)
			cin >> buff[0][i];
		cout << "Номера строк\n";
		for (int i = 0; i < p; i++)
			cin >> buff[1][i];
		minor1 = new int* [p];
		for (int i = 0; i < p; i++)
			minor1[i] = new int[p];
		minor2 = new int* [p];
		for (int i = 0; i < p; i++)
			minor2[i] = new int[p];
		int temp2 = 0, temp1 = 0;
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor1[i][j] = matr[buff[1][temp2]][buff[0][temp1]];
				temp1++;
			}
			temp1 = 0;
			temp2++;
		}
		cout << "Номера столбцов\n";
		for (int i = 0; i < p; i++)
			cin >> buff[2][i];
		cout << "Номера строк\n";
		for (int i = 0; i < p; i++)
			cin >> buff[3][i];
		temp2 = 0;
		temp1 = 0;
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				minor2[i][j] = matr[buff[3][temp2]][buff[2][temp1]];
				temp1++;
			}
			temp1 = 0;
			temp2++;
		}
	}
	// Minor 1 + Minor 2
	void Add() {
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << *(minor1[i] + j) + *(minor2[i] + j) << "\t";
			}
			cout << endl;
		}
	}
	// Minor 1 + A and Minor 2 + A
	void Add(int a) {
		cout << "Minor 1 + A:\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << *(minor1[i] + j) + a << "\t";
			}
			cout << endl;
		}
		cout << "Minor 2 + A:\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << *(minor2[i] + j) + a << "\t";
			}
			cout << endl;
		}
	}
	// Minor 1 - Minor 2
	void Subtract() {
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << *(minor1[i] + j) - *(minor2[i] + j) << "\t";
			}
			cout << endl;
		}
	}
	// Minor 1 - A and Minor 2 - A
	void Subtract(int a) {
		cout << "Minor 1 - A:\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << *(minor1[i] + j) - a << "\t";
			}
			cout << endl;
		}
		cout << "Minor 2 - A:\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << *(minor2[i] + j) - a << "\t";
			}
			cout << endl;
		}
	}
	// Minor 1 * Minor 2
	void Multiplication() {
		int buff = 0;
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				for (int q = 0; q < p; q++) {
					buff += minor1[i][q] * minor2[q][j];
				}
				cout << buff << "\t";
			}
			cout << endl;
		}
	}
	// Minor 1 * A and Minor 2 * A
	void Multiplication(int a) {
		cout << "Minor 1 * A:\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << *(minor1[i] + j) * a << "\t";
			}
			cout << endl;
		}
		cout << "Minor 2 * A:\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << *(minor2[i] + j) * a << "\t";
			}
			cout << endl;
		}
	}
	void OutputMain() {
		cout << "Матрица\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << matr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "Минор 1\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << minor1[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "Минор 2\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << minor2[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void MinorsMain() {
		cout << "Минор 1\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << minor1[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "Минор 2\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << minor2[i][j] << "\t";
			}
			cout << endl;
		}
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
				cout << minor1[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Minor() {
		cout << "Минор\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << minor1[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void ChangeMinor(int neww, int i, int j) {
		minor1[i][j] = neww;
	}
	int GetP() {
		return p;
	}
	int GetElement(int i, int j) {
		return minor1[i][j];
	}
	void OutMinor(Matrix* obj, int a) {
		cout << "Минор\n";
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				cout << obj[a].minor1[i][j] << "\t";
			}
			cout << endl;
		}
	}
	~Matrix() {
		for (int i = 0; i < n; i++)
			delete[] matr[i];
		delete[] matr;
		for (int i = 0; i < p; i++)
			delete[] minor1[i];
		delete[] minor1;
		/*for (int i = 0; i < p; i++)
			delete[] minor2[i];
		delete[] minor2;
		for (int i = 0; i < 4; i++)
			delete[] buff[i];
		delete[] buff;*/
	}
};

void Task(Matrix* obj) {
	int neww, m, p, c;
	cout << "Минор какой матрицы изменить: ";
	cin >> m;
	cout << "На какое число умножить минор: ";
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
	int k, num;
	cout << "Матрица с 2 минорами\n";
	Matrix mat(true);
	system("cls");
	cout << "Введите количество матриц: ";
	cin >> k;
	Matrix* obj = new Matrix[k];
	bool flag = true;
	bool flag1 = true;
	int w = rand() % k;
	Matrix copyOfW(obj[w]);
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
				cout << "Введите номер нужного пункта\n0.Выход\n1.Вывод матрицы и 2 миноров.\n2.Перегрузка суммирования.\n3.Перегрузка вычитания.\n4.Перегрузка умножения" << endl;
				cin >> choice1;
				switch (choice1) {
				case 0:
					flag1 = false;
					break;
				case 1:
					system("cls");
					mat.OutputMain();
					system("pause");
					break;
				case 2:
					cout << "Введите константу: ";
					cin >> num;
					system("cls");
					mat.MinorsMain();
					cout << "Сумма миноров:\n";
					mat.Add();
					cout << "Сумма миноров с введённой константой:\n";
					mat.Add(num);
					system("pause");
					break;
				case 3:
					cout << "Введите константу: ";
					cin >> num;
					system("cls");
					mat.MinorsMain();
					cout << "Разность миноров:\n";
					mat.Subtract();
					cout << "Разность миноров с введённой константой:\n";
					mat.Subtract(num);
					system("pause");
					break;
				case 4:
					cout << "Введите константу: ";
					cin >> num;
					system("cls");
					mat.MinorsMain();
					cout << "Произведение миноров:\n";
					mat.Multiplication();
					cout << "Проивзедение миноров с введённой константой:\n";
					mat.Multiplication(num);
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
}