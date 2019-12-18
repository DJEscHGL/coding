#include <iostream>

using namespace std;

const int n = 2;
const int m = 3;

void input(int array[n][m])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Введите a[" << i << "][" << j << "] = ";
			cin >> array[i][j];
			if (array[i][j] < 1 || array[i][j] > 10)
			{
				cout << "Неверное значение, повторите ввод..." << endl;
				cout << "Введите a[" << i << "][" << j << "] = ";
				cin >> array[i][j];
			}
		}
	}
}

bool check(int newarray[m])
{
	for (int i = 0; i < m; i++)
	{
		if (newarray[i] < 9)
			return false;
	}
	return true;
}

int search(int array[n][m]) 
{
	int s = 0;
	int newarray[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int q = array[i][j];
			newarray[j] = q;
		}
		if (check(newarray))
			s++;
	}
	return s;
}
int main()
{
	setlocale(0, "");
	int array[n][m];
	input(array); 
	cout << search(array);
}