#include <iostream>
#include <windows.h>

using namespace std;

HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Addition(int *first_num, int *second_num, int* sum, int sum_size) {
	int buff;
	int k = sum_size - 2;
	for (int j = sum_size - 1; j > 0; j--){
		buff = first_num[k] + second_num[k];
		if (buff > 9) {
			sum[j] += buff % 10;
			sum[j - 1] += buff / 10;
		}
		else
			sum[j] += buff;
		k--;
	}
}

void Output(int *sum, int sum_size){
	SetConsoleTextAttribute(hconsole, 5);
	for (int i = 0; i < sum_size; i++)
		cout << *(sum + i);
	SetConsoleTextAttribute(hconsole, 7);
}

int main(){
	int Fst_size, Snd_size, sum_size;
	int* first_num, * second_num;
	cout << "The size of the 1st number is ";
	cin >> Fst_size;
	cout << "The size of the 2nd number is ";
	cin >> Snd_size;
	if (Fst_size >= Snd_size) {
		first_num = new int[Fst_size];
		second_num = new int[Fst_size];
		sum_size = Fst_size;
		cout << "1st num write digits separated by space... ";
 		for (int i = 0; i < sum_size; i++)
			cin >> first_num[i];
		cout << "2nd num write digits separated by space... ";
		for (int i = 0; i < sum_size; i++) {
			if (i < sum_size - Snd_size)
				second_num[i] = 0;
			else
				cin >> second_num[i];
		}
	}
	else {
		first_num = new int[Snd_size];
		second_num = new int[Snd_size];
		sum_size = Snd_size;
		cout << "1st num write digits separated by space... ";
		for (int i = 0; i < sum_size; i++) {
			if (i < sum_size - Fst_size)
				first_num[i] = 0;
			else
				cin >> first_num[i];
		}
		cout << "2nd num write digits separated by space... ";
		for (int i = 0; i < sum_size; i++)
			cin >> second_num[i];
	}
	sum_size++;
	int* sum = new int[sum_size];
	for (int *i = sum; i < sum + sum_size; i++) {
		*i = 0;
	}
	Addition(first_num, second_num, sum, sum_size);
	Output(sum, sum_size);
	delete[] sum;
	delete[] first_num;
	delete[] second_num;
}