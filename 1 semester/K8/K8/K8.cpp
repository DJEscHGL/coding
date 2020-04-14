#include <iostream>
#include <cmath>

using namespace std;

double Min(double x, double y)
{
	if (abs(x * y) > 1)
	{
		if (x > y)
			return y;
		else
			return x;
	}
	else
	{
		if (x > (x - y) && (x - y) > 0)
			return 0;
		else if (x > (x - y) && (x - y) < 0 && x > 0)
				return x - y;
			else
				return x;
	}
}

void Initial(double x[], double y[], double z[], int n);

int main()
{
	setlocale(0, "");
	const int n = 7;
	double x[n], y[n], z[n];
	cout << "Массив Х:" << endl;
	for (int i = 0; i < 7; i++)
		cin >> x[i];
	cout << "Массив Y:" << endl;
	for (int i = 0; i < 7; i++)
		cin >> y[i];
	cout << "Массив Z:" << endl;
	Initial(x, y, z, n);
	for (int i = 0; i < 7; i++)
		cout << z[i] << " ";

}

void Initial(double x[], double y[], double z[], int n)
{
	for (int i = 0; i < n; i++)
		z[i] = Min(x[i], y[i]);
}