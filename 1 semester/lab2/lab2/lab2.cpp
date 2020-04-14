#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>


using namespace std;

void Output(int N, int** MyArray)
{
	int Nn = N - 2;
	
}

int main()
{
	srand(time(NULL));
	int N, count;
	cout << "N = ";
	cin >> N;
	int** MyArray = new int* [N];
	for (count = 0; count < N; count++)
		MyArray[count] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			MyArray[i][j] = rand() % 100;
	cout << endl;
	Output(N, MyArray);
	for (count = 0; count < N; count++)
		delete[] MyArray[count];
}