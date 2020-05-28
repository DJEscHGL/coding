/*
	Написать функцию, которая во введенном массиве находит все
	числа, вычисляемые как факториал от некоторого числа. Вывести на экран эти числа, а также числа, факториалом которых
	они являются.
*/		

#include <iostream>

using namespace std;

void factorial(int a)
{
	unsigned long long int i, j, k;
	unsigned long long int* MyArray = new unsigned long long int[a];
	for (i = 0; i < a; i++)
		cin >> MyArray[i];		// Ввод массива
	for (i = 0; i < a; i++)
	{
		k = 1;									// Алгоритм проверки на факториал + вычисление факторила
		for (j = 1; k < MyArray[i]; j++)
		{
			k *= j;
		}
		if (k == MyArray[i] && k == 1)
			cout << "Число " << MyArray[i] << " факториал чисел 0 и 1" << endl;
		else if (k == MyArray[i])
			cout << "Число " << MyArray[i] << " факториал числа " << j - 1 << endl;
		//else cout << "Число " << MyArray[i] << " не является факториалом" << endl;
	}
	delete[] MyArray;
}

int main()
{
	unsigned long long int n;  // Счётчик и размер массива
	setlocale(0, "");
	cout << "Введите размер массива = ";
	cin >> n;
	cout << endl;
	cout << "Введите массив:" << endl;
	factorial(n);
	return 0;
}