#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	const int n = 5, m = 8;
	int oldarray[n][m];
	int newarray[3][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			oldarray[i][j] = rand() % 51 - 25;
			newarray[0][j] = 0;
			newarray[1][j] = 0;
			newarray[2][j] = 0;
			cout << oldarray[i][j] << " ";
		}
		cout << endl;
	}
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
		{
			if (oldarray[i][j] > 0)
			{
				newarray[0][j] = j;
				newarray[1][j]++;
				newarray[2][j] += oldarray[i][j];
			}
		}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << newarray[i][j] << " ";
		}
		cout << endl;
	}
}