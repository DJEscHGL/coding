#include<iostream>
#include<Windows.h>

using namespace std;

class Sort {
	static const int n = 5, m = 3;
	int matrix[n][m], sumAndNum[n][2];
	int max = 0;
public:
	Sort() {
	}
	void Input() {
		cout << "Введите матрицу:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> matrix[i][j];
			}
			sumAndNum[i][0] = 0;
			sumAndNum[i][1] = 0;
		}
	}
	void Count() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] > 0) {
					sumAndNum[i][1]++;
					sumAndNum[i][0] += matrix[i][j];
				}
			}
			if (sumAndNum[i][0] > sumAndNum[max][0])
				max = i;
		}
		for (int i = 0; i < m; i++)
			matrix[max][i] = 0;
		max++;
	}
	void Sor(){
		for (int i = max; i < n - 1; i++) {
			for (int j = max; j < n - 1; j++) {
				if (sumAndNum[j][1] < sumAndNum[j + 1][1]) {
					swap(sumAndNum[j][1], sumAndNum[j + 1][1]);
					swap(sumAndNum[j][0], sumAndNum[j + 1][0]);
					swap(matrix[j], matrix[j + 1]);
				}
			}
		}
	}
	void Output() {
		system("cls");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	~Sort() {
	}
};

int main() {
	setlocale(0, "");
	Sort matr;
	matr.Input();
	matr.Count();
	matr.Sor();
	matr.Output();
	matr.~Sort();
}