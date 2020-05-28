#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int NotMain(int q)
{
	int s = 0, p, i = 0, t = 0;
	if (q == 1)
	{
		cout << q << " количество нулей = ";
		return 0;
	}
	else if (q == 0)
	{
		cout << q << " количество нулей = ";
		return 1;
	}
	else
	{
		while (q >= 1)
		{
			p = q % 2;
			if (p == 0)
			{
				t++;
				s++;
			}
			else
			{
				i += p * pow(10, t);
				t++;
			}
			q /= 2;
		}
	}
	cout << i <<  " количество нулей = ";
	return(s);
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