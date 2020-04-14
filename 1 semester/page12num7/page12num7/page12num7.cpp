/*
	Определить значение функции для любых вводимых значений x и y, предварительно определив D
*/

#include <iostream>
#include <cmath>

using namespace std;

int x, y, z;
double Z;

int main()
{
	setlocale(0, "");
	cout << "Введите x = ";
	cin >> x;
	cout << endl;
	cout << "Введите y = ";
	cin	>> y;
	cout << endl;
	Z = sqrt(x * y);
	if (floor(Z) == Z)
		cout << -1;
	else	
}