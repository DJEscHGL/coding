#include <iostream>

using namespace std;

void Generate(int N, double* A, double* C)
{

}

int main()
{
	int N;
	cout << "N = ";
	cin >> N;
	double* A = new double[N + 2];
	double* C = new double[N];
	cout << "A[0] = ";
	cin >> A[0];
	cout << "A[" << N << "] = ";
	cin >> A[N];
	for (int i = 0; i < N; i++)
	{
		cout << "C[" << i + 1 << "] = ";
		cin >> C[i];
	}
	Generate(N, A, C);
}