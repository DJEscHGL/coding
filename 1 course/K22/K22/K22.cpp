#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	int n;
	cout << "N = ";
	cin >> n;
	int** newarray = new int* [n];
	for (int i = 0; i < n; i++)
		newarray[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			newarray[i][j] = rand() % 50 + 50;
			cout << newarray[i][j] << " ";
		}
		cout << endl;
	}
	// LEFT DOWN
	cout << endl << "LEFT DOWN" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= i)
				cout << newarray[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	// RIGHT UP
	cout << endl << "RIGHT UP" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j >= i)
				cout << newarray[i][j] << " ";
			else
				cout << "   ";
		}
		cout << endl;
	}
	// RIGHT DOWN
	cout << endl << "RIGHT DOWN" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + i >= n - 1)
				cout << newarray[i][j] << " ";
			else
				cout << "   ";
		}
		cout << endl;
	}
	// LEFT UP
	cout << endl << "LEFT UP" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + i <= n - 1)
				cout << newarray[i][j] << " ";
			else
				cout << "   ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		delete newarray[i];
}