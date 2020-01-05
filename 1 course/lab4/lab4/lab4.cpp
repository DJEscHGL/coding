#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void check(const int m, int newarray[], int& sum, int& num)
{
	sum = 0;
	num = 0;
	int p;
	int q;
	for (int i = 0; i < m; i++)
	{
		q = 0;
		p = newarray[i] % 100;
		q += newarray[i] % 10 + newarray[i] / 10;
		if (p < 100 && p > 10 && q % 2 != 0)
		{
			sum += newarray[i];
			num++;
		}
	}
}

int main()
{
	int sum, num;
	const int n = 3;
	const int m = 3;
	int matrix[n][m];
	int newarray[m]; // строка матрицы для функции
	int secondarray[3][n]; // вывод
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 50;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			newarray[j] = matrix[i][j];
		}
		check(m, newarray, sum, num);
		secondarray[0][i] = i;
		secondarray[1][i] = num;
		secondarray[2][i] = sum;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
			cout << secondarray[i][j] << " ";
		cout << endl;
	}
}