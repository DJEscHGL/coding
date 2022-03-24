#include <iostream>

using namespace std;

bool findNegative(double** arr, int n, int mm) {
	for (int i = 0; i < n; i++) {
		if (arr[mm][i] < 0)
			return true;
	}
}

int main() {
	setlocale(0, "");
	double sum = 0;
	double** arr;
	int n, m;
	cout << "Введите n = ";
	cin >> n;
	cout << "Введите m = ";
	cin >> m;
	arr = new double*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new double[m];
	cout << "Заполните массив:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		if (findNegative(arr, n, i))
		{
			for (int j = 0; j < n; j++) {
				sum += arr[j][i];
			}
			cout << "Сумма столбца " << i << " равна " << sum << endl;
			sum = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		delete arr[i];
	}
	delete arr;
}