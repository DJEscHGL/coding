#include <iostream>

using namespace std;

int NotMain(int q)
{
	while (q >= 10)
		q /= 10;
	return(q);
}

void NotNotMain(int q)
{
	cout << NotMain(q) << endl;
}

int main()
{
	setlocale(0, "");
	int n;
	cout << "Размер массива = ";
	cin >> n;
	cout << endl;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> array[i];
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		NotNotMain(array[i]);
}