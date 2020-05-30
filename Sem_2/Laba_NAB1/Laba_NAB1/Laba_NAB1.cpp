#include <iostream>
#include <Windows.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Matrix {
private:
	int* num;
	double** matr;
	int n, m;
public:
	Matrix(int a, int b) {
		n = a;
		m = b;
		num = new int[n];
		matr = new double* [n];
		for (int i = 0; i < n; i++) {
			matr[i] = new double[m];
			num[i] = 0;
		}
	}

	void input(){
		cout << "Input matrix:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> *(matr[i] + j);
			}
		}
	}

	void count() {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = j + 1; k < m; k++) {
					if (*(matr[i] + j) == *(matr[i] + k)) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					num[i]++;
				}
				flag = false;
			}
		}
	}

	void output(){
		SetConsoleTextAttribute(hConsole, 4);
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << *(num + i) << " ";
		}
		SetConsoleTextAttribute(hConsole, 7);
	}
};

int main() {
	int n, m;
	cout << "N = ";
	cin >> n;
	cout << "M = ";
	cin >> m;
	cout << endl;
	Matrix newmatr(n, m);
	newmatr.input();
	newmatr.count();
	newmatr.output();
}