
#include <iostream>
#include <stack>
#include <Windows.h>

using namespace std;

class Work
{
	int n;
	double *newarray;
public:
	Work(int SIZE)
	{
		n = SIZE;
		newarray = new double[n];
	}
	void Input()
	{
		double* arr = newarray;
		for (int i = 0; i < n; i++)
			cin >> *(arr + i);
	}
	void Output()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int i = 0; i < n; i++)
		{
			if(*(newarray + i) == 0)
				SetConsoleTextAttribute(hConsole, 6);
			else if(*(newarray + i) < 0)
				SetConsoleTextAttribute(hConsole, 2);
			else
				SetConsoleTextAttribute(hConsole, 3);
			cout << *(newarray + i) << " ";
		}
		SetConsoleTextAttribute(hConsole, 7);
	}
	void Sort()
	{
		stack <double> positive;
		stack <double> negative;
		for (double *i = newarray; i < newarray + n; i++)
		{
			if (*(i) > 0)
				positive.push(*(i));
			else if (*(i) < 0)
				negative.push(*(i));
		}
		int j = n - 1;
		while (!positive.empty())
		{
			*(newarray + j) = positive.top();
			positive.pop();
			j--;
		}
		while (!negative.empty())
		{
			*(newarray + j) = negative.top();
			negative.pop();
			j--;
		}
		while (j >= 0)
		{
			*(newarray + j) = 0;
			j--;
		}
	}
	~Work()
	{
		delete[] newarray;
		newarray = NULL;
	}
};

void main()
{
	int SIZE;
	cout << "SIZE = ";
	cin >> SIZE;
	Work arr(SIZE);
	arr.Input();
	arr.Sort();
	arr.Output();
	arr.~Work();
}