/*
	Вывести на экран треугольник Паскаля, состоящий из n строк.
	Коэффициенты треугольника вычисляются по формуле
	C(m,n) = n! / m! * (n - m)!
*/
#include <iostream>

using namespace std;


long double Cnm(int N, int M)
{
	double Sum = 1;
	int i;
	for (i = 1; i <= M; i++)
		Sum *= (N - i + 1) / float(i);
	return Sum;
}

int main()
{
	setlocale(0, "");
	int n, j, i;
	cout << "Введите число строк = ";
	cin >> n; 
	cout << endl;
	for (j = 0; j <= n; j++) {
		for (i = 0; i <= j; i++)
			cout << Cnm(j, i) << " ";
		cout << endl;
	}
	return 0;
}