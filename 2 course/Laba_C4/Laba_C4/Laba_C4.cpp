#include <iostream>
#include <Windows.h>

using namespace std;

void Output()
{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << a[i][j] << "*x" << j;
				if (j < n - 1)
					cout << " + ";
			}
			cout << " = " << y[i] << endl;
		}
}

int main()
{
	int SIZE;
	cout << "SIZE = ";
	cin >> SIZE;
	double** Arr, * FT, * x;
	Arr = new double* [SIZE];
	FT = new double[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "EQUATION = ";
		Arr[i] = new double[SIZE];
		for (int j = 0; j < SIZE; j++)
			cin >> *(Arr[i] + j);
		cout << "FT = ";
		cin >> *(FT + i);
	}

}
