#include <iostream>

using namespace std;

void search(int q, int& sum, int& max)
{
	sum = 0;
	max = 0;
	while (q != 0)
	{
		sum += q % 10;
		if (q % 10 > max)
			max = q % 10;
		q /= 10;
	}
}

int main()
{
	int max, sum;
	const int n = 3;
	int newarray[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> newarray[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i + j == n - 1)
			{
				search(newarray[i][j], sum, max);
				cout << sum << " " << max << endl;
			}
		}
}