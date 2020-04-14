#include <iostream>
#include <cmath>

using namespace std;

int Number(int n)
{
	//Простая функция для последней цифры числа
	return(abs(n % 10));
}

//Прототип второй функции
void Output(int n, int SecArray[]);

int main()
{
	//Задаём размер массива, инициализируем и заполняем
	setlocale(0, "");
	int N;
	cout << "Размер массива = ";
	cin >> N;
	cout << endl << "Заполните массив:" << endl;
	int* NewArray = new int[N];
	for (int i = 0; i < N; i++)
		cin >> NewArray[i];
	cout << endl;
	Output(N, NewArray);
	delete[] NewArray;
}

void Output(int n, int SecArray[])
{
	//Прогоняем весь массив, вызываем первую функцию и выводим лесенкой
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < i; k++)
			cout << " ";
		cout << SecArray[i] << " -- " << Number(SecArray[i]) << endl;
	}
}