#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

class Sort
{
	int n;
	double* x;
	double* y;
	double* dist;
public:
	Sort(int Size)
	{
		n = Size;
		x = new double[n];
		y = new double[n];
		dist = new double[n];
	}
	void Input()
	{
		double* newx = x;
		double* newy = y;
		for (int i = 0; i < n; i++)
		{
			cout << "x[" << i << "] = ";
			cin >> *(newx + i);
			cout << "y[" << i << "] = ";
			cin >> *(newy + i);
		}
	}
	void Output()
	{
		HANDLE MyPS4 = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(MyPS4, 2);
		for (int i = 0; i < n; i++)
		{
			cout << *(x + i) << " 	 ";
		}
		cout << endl;
		SetConsoleTextAttribute(MyPS4, 7);
		for (int i = 0; i < n; i++)
		{
			cout << *(y + i) << " 	 ";
		}
		cout << endl;
		SetConsoleTextAttribute(MyPS4, 6);
		for (double *i = dist; i < dist + n; i++)
		{
			cout << *(i) << "  ";
		}
		SetConsoleTextAttribute(MyPS4, 7);
	}
	void SelectionSort()
	{
		int min;
		for (int i = 0; i < n; i++)
		{
			*(dist + i) = sqrt((*(x + i)) * (*(x + i)) + (*(y + i)) * (*(y + i)));
		}
		for (int i = 0; i < n - 1; i++)
		{
			min = i;
			for (int j = i + 1; j < n; j++)
			{
				if (*(dist + j) < *(dist + min))
					min = j;
			}
			swap(*(dist + i), *(dist + min));
			swap(*(x + i), *(x + min));
			swap(*(y + i), *(y + min));
		}	
	}
	~Sort()
	{
		delete[] x;
		x = NULL;
		delete[] y;
		y = NULL;
		delete[] dist;
		dist = NULL;
	}
};

void main()
{
	int Size;
	cout << "Size = ";
	cin >> Size;
	while (Size <= 0)
	{
		cout << "Error...";
		cout << "Size = ";
		cin >> Size;
	}
	Sort Points(Size);
	Points.Input();
	Points.SelectionSort();
	Points.Output();
	Points.~Sort();
}