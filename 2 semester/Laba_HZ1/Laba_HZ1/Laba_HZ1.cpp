#include<iostream>
#include<Windows.h>

HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

class Normal {
private:
	int n, m;
	double maxi = 0.0;
	double* max;
	int** matrix;
public:
	Normal(int a, int b) {
		n = a;
		m = b;
		matrix = new int* [n];
		for (int i = 0; i < m; i++)
			matrix[i] = new int[m];
		max = new double[n];
	}
	void Input() {
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				cin >> matrix[i][j];
			max[i] = 0;
		}
	}
	void Output() {
		system("cls");
		SetConsoleTextAttribute(hconsole, 3);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << matrix[i][j] << " ";
			cout << " | " << max[i] << endl;
		}
		for (int i = 0; i < m * 2 + 3; i++)
			cout << "=";
		cout << "\nNorma is " << maxi;
		SetConsoleTextAttribute(hconsole, 7);
	}
	void Counting() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				max[i] += abs(matrix[i][j]);
		for (int i = 0; i < n; i++) {
			if (max[i] > maxi)
				maxi = max[i];
		}
	}
};

int main() {
	int n, m;
	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;
	Normal matrix(n, m);
	matrix.Input();
	matrix.Counting();
	matrix.Output();
}