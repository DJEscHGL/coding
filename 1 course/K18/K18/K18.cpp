#include <iostream>
#include <cmath>

using namespace std;

int sum(const int n, int a[])
{
	int s = 0;
	if (a[0] == 0)
		return 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i]) != 0)
			s += abs(a[i]);
		else
			return s;
	}
	return s;
}

int main()
{
	const int n = 5;
	int a[n];
	int array[n][n] = { 0, 2, 3, 4, 5, 0, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 0, 23, 24, 25 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[j] = array[i][j];
			cout << array[i][j] << " ";
		}
		cout << sum(n, a);	
		cout << endl;
	}
}