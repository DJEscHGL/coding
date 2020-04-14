#include <iostream>
#include <ctime>

using namespace std;

void progressia(int SIZE, double *myarray)
{
	int maxsize = 0, newmaxsize = 1, firstnum = 0, newfirstnum;
	double mult = 0, newmult = 0, previousnum;
	for (int i = 1; i < SIZE; ++i)
		for (int j = 0; j < SIZE - 1; j++)
			if (myarray[j + 1] < myarray[j])
				swap(myarray[j + 1], myarray[j]);
	for (int i = 0; i < SIZE; i++)
		cout << myarray[i] << " ";
	cout << endl;
	for (int i = 0; i <= SIZE - 1; i++)
	{
		if (myarray[i] == 0)
			continue;
		newfirstnum = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			previousnum = myarray[i];
			newmult = myarray[j] / myarray[i];
			for (int k = i + 1; k < SIZE; k++)
			{
				if (myarray[k] / newmult == previousnum)
				{
					newmaxsize++;
					previousnum = myarray[k];
				}
			}
			if (newmaxsize >= maxsize)
			{
				maxsize = newmaxsize;
				mult = newmult;
				firstnum = newfirstnum;
			}
			newmaxsize = 1;
			newfirstnum = 0;
		}
	}
	cout << myarray[firstnum] << " ";
	previousnum = myarray[firstnum];
	for (int i = firstnum + 1; i < SIZE; i++)
	{
		if (myarray[i] / mult == previousnum)
		{
			cout << myarray[i] << " ";
			previousnum = myarray[i];
		}
	}
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int SIZE; 
	cout << "SIZE = ";
	cin >> SIZE;
	double* myarray = new double [SIZE] {1, 3, 7, 9, 27, 49, 81, 4, 16, 64, 256, 1024, 729, 243, 0}; // 15
	/*for (int i = 0; i < SIZE; i++)
		myarray[i] = rand() % 50;*/
	progressia(SIZE, myarray);
	delete [] myarray;
}