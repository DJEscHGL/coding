#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	//const n = 5;
	//int array[n];
	int n;
	cin >> n;
	int* array = new int[n];//это сложный вариант
	for (int i = 0; i < n; i++)
		cin >> array[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (abs(array[j] % 10) > abs(array[j + 1] % 10)) // т к мы сравниваем по последней цифре
			{
				swap(array[j], array[j + 1]); // swap(a, b) меняет значение переменной a на значение b и b на значение a
				/*
				если не использовать swap:
				a = array[j];
				b = array[j+1];
				array[j] = b;
				array[j + 1] = a;
				*/
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
}