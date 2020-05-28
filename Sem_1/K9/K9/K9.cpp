#include <iostream>
#include <cmath>

using namespace std;

double max = 0;
int q = 0;

double length(double x1, double y1, double x2, double y2)
{
	return(sqrt(pow(x1-x2, 2) + pow(y1 - y2, 2)));
}

void check(int n, double x[], double y[]);

int main()
{
	setlocale(0, "");
	int N;
	cout << "Количество точек = ";
	cin >> N;
	double* X = new double[N];
	double* Y = new double[N];
	for (int i = 0; i < N; i++)
	{
		cout << "X[" << i << "] = ";
		cin >> X[i];
		cout << "Y[" << i << "] = ";
		cin >> Y[i];
		cout << endl;
	}
	check(N, X, Y);
	cout << "Максимальное расстояние у точки (" << X[q] << ";" << Y[q] << ") равное " << max;
}

void check(int n, double x[], double y[])
{
	double k;
	for (int i = 0; i < n; i++)
	{
		k = length(x[i], y[i], 0, 0);
		if (k > max)
		{
			max = k;
			q = i;
		}
	}
}