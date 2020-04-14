#include <iostream>

using namespace std;

//Первая функция с прототипом
void Input(int n, int SecArray[]);

bool Check(int n, int SecArray[])
{
	//Проверяем оценки
	for (int i = 0; i < n; i++)
	{
		if (SecArray[i] >= 9)
			continue;
		else
			return 0;
	}
	return 1;
}

int main()
{
	//Задаём размер массива и инициализируем
	setlocale(0, "");
	int N;
	cout << "Размер массива = ";
	cin >> N;
	cout << endl;
	int* NewArray = new int[N];
	//Вызываем функцию ввода
	Input(N, NewArray);
	//Вызываем функцию проверки и по полученному результату выводим нужное
	if (Check(N, NewArray))
		cout << "Отличник";
	else
		cout << "Не отличник";
	delete[] NewArray;
}

void Input(int n, int SecArray[])
{
	//Заполняем массив данными
	cout << "Введите оценки в промежутке 0..10:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> SecArray[i];
		//Проверка на правильность введённого числа
		if (SecArray[i] > 10 || SecArray[i] < 1)
		{
			cout << "Оценка за пределами промежутка. Введите заново" << endl;
			cin >> SecArray[i];
		}
	}
}