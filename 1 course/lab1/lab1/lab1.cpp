#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int count, n1, n2, p = 0, k;
	const int N = 2;
	const int n = N * N;
	int A[n];
	for (int i = 0; i < n; i++)
		A[i] = 0;
	srand(time(NULL));
	cout << "n1 = ";
	cin >> n1;
	cout << endl << "n2 = ";
	cin >> n2;
	int Array[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			bool flag = false;
			while (flag == false)
			{
				k = rand() % n2 + n1;
				for (int q = 0; q <= p; q++)
				{
					if (A[q] == k)
						flag = false;
				}
				if (flag == false)
					continue;
				else
					break;
			}
			Array[i][j] = k;
			A[p] = Array[i][j];
			p++;
		}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Array[i][j] << " ";
		cout << endl;
	}
}