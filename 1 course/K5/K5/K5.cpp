#include <iostream>

using namespace std;

//Прототип второй функции
void Output(int n, int SecArray[]);

int Search(int n, int SecArray[])
{
	int q = 0, w = 0, p = 0;
	p = SecArray[0];
	//Ищем нужное число и проверям граничные условия 
	for (int i = 0; i < n; i++)
	{
		if (SecArray[i] > 0)
			q = SecArray[i];
		if (SecArray[i] == p)
			w++;
	}
	if (w == n)
		return SecArray[0];
	else if (q == 0)
		return -1;
	else
		return q;
}

int main()
{
	setlocale(0, "");
	int N, q;
	//Спрашиваем размер массива, инициализируем и заполняем его
	cout << "Размер массива = ";
	cin >> N;
	cout << endl;
	cout << "Введите массив:" << endl;
	int* NewArray = new int [N] ;
	for (int i = 0; i < N; i++)
		cin >> NewArray[i];
	cout << endl;
	//Вызываем первую функцию, проверям результат и выводим нужное
	q = Search(N, NewArray);
	if (q == -1)
		cout << "Нет положительных чисел" << endl << endl;
	else
		cout << "Ответ " << q << endl << endl;
	//Вызываем вторую функцию
	Output(N, NewArray);
	delete[] NewArray;
}

void Output(int n, int SecArray[])
{
	for (int i = 0; i < n; i += 2)
	{
		//Вообще можно было сделать гораздо проще используя библиотеку iomanip
		for (int k = n; k > i; k--)
			cout << " ";
		cout << " " << SecArray[i] << " " << SecArray[i + 1] << endl;
	}
} 