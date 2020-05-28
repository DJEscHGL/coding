#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");
	double a, b, c, u, v, min;
	cout << "a = ";
	cin >> a;
	cout << endl << "b = ";
	cin >> b;
	cout << endl << "c = ";
	cin >> c;
	cout << endl << "u = ";
	cin >> u;
	cout << endl << "v = ";
	cin >> v;
	//Тут вроде всё понятно. Точность 0,001 это размер шага для функции
	min = a * u * u + b * u + c;
	for (; u <= v; u += 0.001)
	{
		if(min > (a * u * u + b * u + c))
			min = a * u * u + b * u + c;
	}
	cout << endl << "Минимум = " << min;
}