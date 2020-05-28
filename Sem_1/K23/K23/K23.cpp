#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//template <class T>
void search(int m, double secondarray[], double& min, double& max)
{
	min = secondarray[0];
	max = secondarray[0];
	for (int i = 0; i < m; i++)
	{
		if (secondarray[i] > max)
			max = secondarray[i];
		if (secondarray[i] < min)
			min = secondarray[i];
	}
}

int main()
{
	double min, max;
	srand(time(NULL));
	int n, m;
	cout << "N = ";
	cin >> n;
	cout << "M = ";
	cin >> m;
	double *secondarray = new double[m];
	double** newarray = new double *[n];
	for (int i = 0; i < n; i++)
		newarray[i] = new double[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			//newarray[i][j] = rand() % 50;
			cin >> newarray[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			secondarray[j] = newarray[i][j];
		}
		search(m, secondarray, min, max);
		cout << "Min = " << min << "; Max = " << max << ";  ";
		for (int q = 0; q < m; q++)
			cout << secondarray[q] << " ";
		cout << endl;
	}
}