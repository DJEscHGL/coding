#include <iostream>

using namespace std;

bool check(int q)
{
	if (q >= 10 && q <= 15)
		return true;
	while (q > 15)
	{
		if (q % 16 >= 10)
			return true;
		q /= 16;
	}
	return false;
}

int main()
{
	int s = 0;
	const int n = 5;
	int array[n][n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i + j) >= (n - 1))
			{
				cout << array[i][j] << "   ";
				if (check(array[i][j]))
					s++;
			}
			else cout << "   ";

		}
		cout << endl;
	}
	cout << s;
}