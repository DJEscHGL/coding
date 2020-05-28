#include <iostream>

using namespace std;

double versh[2][3];

void mediana(double *mx, double *my, int i, int w, int z)
{
	(*mx) = (versh[0][w] + versh[0][z]) / 2;
	(*my) = (versh[1][w] + versh[1][z]) / 2;
}

int main()
{
	setlocale(0, "");
	int q = 0;
	double x = 0, y = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите x" << i << " = ";
		cin >> versh[0][i];
		cout << endl << "Введите y" << i << " = ";
		cin >> versh[1][i];
		cout << endl;
	}
	cout << "Выберите вершину введя число A = 0, B = 1, C = 2. Вариант = ";
	cin >> q;
	if (q == 0)
	{
		mediana(&x, &y, q, 1, 2);
		cout << "Координата медианы из вершины A(" << versh[0][0] << ";" << versh[1][0] << ") = (" << x << ";" << y << ")" << endl;
	}
	else if (q == 1)
	{
		mediana(&x, &y, q, 0, 2);
		cout << "Координата медианы из вершины B(" << versh[0][1] << ";" << versh[1][1] << ") = (" << x << ";" << y << ")" << endl;
	}
	else if (q == 2)
	{
		mediana(&x, &y, q, 0, 1);
		cout << "Координата медианы из вершины C(" << versh[0][2] << ";" << versh[1][2] << ") = (" << x << ";" << y << ")" << endl;
	}
}