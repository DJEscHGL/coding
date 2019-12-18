/*
	Даны целые числа N, M и Y . Напишите программу, которая
	найдет все целые числа X в диапазоне [0, M − 1], такие, что
	X^N mod M = Y,
	где функция mod возвращает остаток от деления.
*/
#include <iostream>
#include <cmath>

using namespace std;

unsigned long long int N, M, Y, X, i;

int main()
{
	setlocale(0, "");
	cout << "Введите N = ";
	cin >> N;
	cout << endl;
	cout << "Введите M = ";
	cin >> M;
	cout << endl;
	cout << "Введите Y = ";
	cin >> Y;
	cout << endl;
	for (X = 0; X <= M - 1; X++)
	{
		i = pow(X, N);
		i %= M;
		if (i == Y)
			cout << X << " ";
	}
	return 0;
} 