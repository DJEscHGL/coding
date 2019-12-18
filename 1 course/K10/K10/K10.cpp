#include <iostream>
#include <conio.h>

using namespace std;

int maximum(int n, int x[])
{
	int w, q, p = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (x[j] > x[j + 1])
			{
				q = x[j];
				w = x[j + 1];
				x[j] = w;
				x[j + 1] = q;
			}
		}
		if (x[i] == x[0])
			p++;
	}
	if (p == n)
		return -1000;
	return x[n - 2];
}

void output(int n, int x[]);

int main()
{
	int n;
	cin >> n;
	int* x = new int[n];
	for (int i = 0; i < n; i++)
		cin >> x[i];
	cout << maximum(n, x) << endl;
	output(n, x);
}

void output(int n, int x[])
{
	for (int i = 0; i < n; i++)
	{
		_getch();
		cout << x[i] << " ";
	}
}