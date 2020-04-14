#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(NULL));
	int N, i = 0, row, column, count, sum = 0, num = 0;
	cout << "N = ";
	cin >> N;
	cout << endl;
	int* numer = new int [N];
	int* sumer = new int[N];
	int** MyArray = new int* [N];
	for (count = 0; count < N; count++)
		MyArray[count] = new int[N];
	/*int** NewArray = new int* [3];
	for (count = 0; count < N; count++)
		NewArray[count] = new int[N];*/
	for (row = 0; row < N; row++)
		for (column = 0; column < N; column++)
			MyArray[row][column] = rand() * rand() % 100;
	for (row = 0; row < N; row++)
	{
		for (column = 0; column < N; column++)
			cout << setw(2) << setprecision(5) << MyArray[row][column] << " ";
		cout << endl;
	}
	cout << endl << endl;
	for (column = 0; column < N; column++)
	{
		for (row = 0; row < N; row++)
		{
			if ((MyArray[row][column] % 2 == 0) && (MyArray[row][column] % 11 == 0) && (MyArray[row][column] != 0))
			{
				sum += MyArray[row][column];
				num++;
			}
		}
		/*NewArray[0][column] = column;
		NewArray[1][column] = num;
		NewArray[2][column] = sum;*/
		numer[column] = num;
		sumer[column] = sum;
		num = 0;
		sum = 0;
	}
	/*for (row = 0; row < 3; row++)
	{
		for (column = 0; column < N; column++)
			cout << setw(6) << setprecision(5) << NewArray[row][column] << " ";
		cout << endl;
	}*/
	for (column = 0; column < N; column++)
	{
		cout << column << "    ";
	}
	cout << endl;
	for (column = 0; column < N; column++)
	{
		cout << numer[column] << "    ";
	}
	cout << endl;
	for (column = 0; column < N; column++)
	{
		cout << sumer[column] << "    ";
	}
	for (count = 0; count < N; count++)
		delete[] MyArray[count];
	/*for (count = 0; count < 3; count++)
		delete[] NewArray[count];*/
}