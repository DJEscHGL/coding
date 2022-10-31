#include<iostream>
#include<windows.h>
using namespace std;

enum menu {
	exitmenu = 0,
	init = 1,
	random = 2,
	input = 3
};

int main() {
	setlocale(0, "");
	srand((unsigned int)time(NULL));
	int n, m, k, menuNum;
	int* arrA, * arrB, *arrC;
	bool flag = true;
	cout << "Enter size n = ";
	cin >> n;
	cout << "Enter size m = ";
	cin >> m;
	k = m + n;
	arrA = new int[n];
	arrB = new int[m];
	arrC = new int[k];
	system("cls");
	cout << "Введите номер нужного пункта\n0.Выход\n1.Массивы при инициализации.\n2.Случайная генерация массивов.\n3.Ручное заполнение массивов" << endl;
	cin >> menuNum;
	switch (menuNum) {
	case menu::exitmenu:
		flag = false;
		break;
	case menu::init:
		system("cls");
		for (int i = 0; i < n; i++) {
			arrA[i] = i;
		}
		for (int i = 0; i < m; i++) {
			arrB[i] = i;
		}
		break;
	case menu::random:
		system("cls");
		for (int i = 0; i < n; i++) {
			arrA[i] = 0 + rand() % 100;
		}
		for (int i = 0; i < m; i++) {
			arrB[i] = 0 + rand() % 200;;
		}
		break;
	case menu::input:
		system("cls");
		cout << "Введите элементы массива А:" <<endl;
		for (int i = 0; i < n; i++) {
			cin >> arrA[i];
		}
		cout << "Введите элементы массива B:" << endl;
		for (int i = 0; i < m; i++) {
			cin >> arrB[i];
		}
		break;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arrA[j] > arrA[j + 1])
				swap(arrA[j], arrA[j + 1]);
		}
	}
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < m - i - 1; j++) {
			if (arrB[j] > arrB[j + 1])
				swap(arrB[j], arrB[j + 1]);
		}
	}
	//TODO main task
	cout << endl;
	for (int i = 0; i < k; i++) {
		cout << arrC[i] << " ";
	}
	delete[] arrA, arrB, arrC;
}