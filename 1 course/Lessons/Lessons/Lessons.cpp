#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void check(int m, int newarray[], int q, int& max, int& positioni, int& positionj)
{
	for (int i = 0; i < m; i++)
	{
		if (newarray[i] > max)
		{
			max = newarray[i];
			positioni = i;
			positionj = q;
		}
	}
}

void output(int n, int m, int* matrix[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void scan(int n, int m, int* matrix[])
{
	int* newarray = new int[m];
	int max = 0, positioni = 0, positionj = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			newarray[j] = matrix[i][j];
		}
		check(m, newarray, max, positioni, positionj, i);
	}
	cout << max << " " << positionj << " " << positioni;
	delete[] newarray;
}

int main()
{
	srand(time(NULL));
	int n, m;
	cout << "N = ";
	cin >> n;
	cout << "M = ";
	cin >> m;
	int count;
	int** matrix = new int* [m];
	for (count = 0; count < n; count++)
		matrix[count] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 10;
	output(n, m, matrix);
	scan(n, m, matrix);
	for (count = 0; count < n; count++)
		delete[] matrix[count];
}