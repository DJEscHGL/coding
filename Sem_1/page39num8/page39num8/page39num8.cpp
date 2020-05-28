#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(NULL)); // Каждый запуск новая генерация рандома
	int N, i = 0, newint, row, column, count, p, q;
	cout << "N = ";
	cin >> N;
	cout << endl;
	// Создание двумерного массива
	int** MyArray = new int* [N];
	for (count = 0; count < N; count++)
		MyArray[count] = new int[N];
	
	/* Ввод данных массива с клавиатуры
	for (row = 0; row < N; row++)
		for (column = 0; column < N; column++)
			{
				cout << "M[" << row << "][" << column << "] = ";
				cin >> MyArray[row][column];
				cout << endl;
			}
	*/
	
	// Заполнение массива рандомными значениями
	for (row = 0; row < N; row++)
		for (column = 0; column < N; column++)
			MyArray[row][column] = rand() * rand() % 3;
	// Вывод массива
	for (row = 0; row < N; row++)
	{
		for (column = 0; column < N; column++)
			cout << setw(6) << setprecision(3) << MyArray[row][column] << " ";
		cout << endl;
	}
	cout << endl << endl;
	// Алгоритм... 
	for (row = 0; row < N; row++)
	{
		for (column = 0; column < N; column++)
		{
			if (MyArray[row][column] == 0)
			{
				for (p = 0; p < N; p++)
				{
					for (q = 0; q < N; q++)
					{
						if ((abs(row - p) + abs(column - q)) == 1)
						{
							if (MyArray[p][q] > 0)
							{
								newint = MyArray[p][q] * -1;
								i++;
							}
						}
					}
				}
				if (i == 1)
					MyArray[row][column] = newint;
				i = 0; 
			}
		}
	}
	cout << endl;
	// Вывод массива
	for (row = 0; row < N; row++)
	{
		for (column = 0; column < N; column++)
			cout << setw(6) << setprecision(3) << abs(MyArray[row][column]) << " ";
		cout << endl;
	}
	// Удаление двумерного массива
	for (count = 0; count < N; count++)
		delete[] MyArray[count];
}