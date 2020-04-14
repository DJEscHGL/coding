#include <iostream>

using namespace std;

void progressia(int n, int x[])
{
	int i, j;
	for (i = 0; i < n; i++) // тут лучше свою сортировку поставь, тут многое, что вам не давали
	{
		bool flag = true;
		for (j = 0; j < n - (i + 1); j++)
		{
			if (x[j] > x[j + 1])
			{
				flag = false;
				swap(x[j], x[j + 1]);
			}
		}
		if (flag)
			break;
	}
	cout << endl;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (x[i] * n == x[j])
			{
				cout << x[i] << " ";
				i = j;
				continue; // это заканчивает цикл преждевременно
			}
		}
		if (j == n && x[i] % n == 0)
			cout << x[i] << " ";
	}
}

int main()
{
	const int n = 6;
	int x[n];
	for (int i = 0; i < n; i++)
		cin >> x[i];
	progressia(n, x);
}