#include <iostream>
#include <Windows.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Work {
	int n;
	double** Mult;
	double** Arr1;
	double** Arr2;
public:
	Work(int SIZE) {
		n = SIZE;
		Mult = new double* [n];
		for (int i = 0; i < n; i++)
		{
			Mult[i] = new double[n];
		}
		Arr1 = new double* [n];
		Arr2 = new double* [n];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j <= i)
				{
					Arr1[i] = new double[j];
					Arr2[i] = new double[j];
				}
			}
		}
	}
	void Input()
	{
		cout << "Left Down Triangle for 1st matrix:\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j <= i)
					cin >> Arr1[i][j];
			}
		}
		cout << "Left Down Triangle for 2st matrix:\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j <= i)
					cin >> Arr2[i][j];
			}
		}
	}
	void OutputTriangle()
	{
		system("cls");
		cout << "First Triangle" << endl;
		SetConsoleTextAttribute(hConsole, 6);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j <= i)
					cout << *(Arr1[i] + j) << " ";
				else
					cout << " ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, 7);
		cout << "Second Triangle" << endl;
		SetConsoleTextAttribute(hConsole, 2);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j <= i)
					cout << *(Arr2[i] + j) << " ";
				else
					cout << " ";
			}
			cout << endl;
		}
	}
	void OutputMult() 
	{
		SetConsoleTextAttribute(hConsole, 7);
		cout << "The Multiplication of Matrix" << endl;
		SetConsoleTextAttribute(hConsole, 3);
		for (int i = 0; i < n; i++)
		{
			for (double* j = Mult[i]; j < Mult[i] + n; j++)
			{
				cout << *(j) << " ";
			}
			cout << endl;
		}
	}
	void Multiplication()
	{
		double a, b;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Mult[i][j] = 0;
				for (int k = 0; k < n; k++)
				{
					if (k > i)
					{
						if (j > k)
						{
							a = Arr1[k][i];
							b = Arr2[j][k];
							Mult[i][j] += a * b;
						}
						else
						{
							a = Arr1[k][i];
							Mult[i][j] += a * Arr2[k][j];
						}
					}
					else
					{
						if (j > k)
						{
							b = Arr2[j][k];
							Mult[i][j] += Arr1[i][k] * b;
						}
						else
							Mult[i][j] += Arr1[i][k] * Arr2[k][j];
					}
				}
			}
		}
	}
	~Work() 
	{
		for (int i = 0; i < n; i++)
		{
			delete Mult[i];
		}
		delete[] Mult;
		Mult = NULL;
		SetConsoleTextAttribute(hConsole, 7);
	}
};

int main() {
	int SIZE;
	cout << "Enter The Size of Array ";
	cin >> SIZE;
	Work arr(SIZE);
	arr.Input();
	arr.OutputTriangle();
	arr.Multiplication();
	arr.OutputMult();
	arr.~Work();
}