#include <iostream>
#include <cmath>

using namespace std;

bool check(int n)
{
	if (n % 2 == 0)
		return true;
	else
		return false;
}

int main()
{
	setlocale(0, "");
	bool flag = true;
	int q;
	const int n = 5;
	int a[n];
	int array[n][n] = {1, 1, 1, 1, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 21, 23, 24, 25 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << " ";
			if(flag)
				if (check(array[i][j]) && flag)
				{
					q = j;
					flag = false;
				}
		}
		if (flag)
			cout << "Нет чётных чисел";
		else 
			cout << q;
		cout << endl;
		flag = true;
	}
}