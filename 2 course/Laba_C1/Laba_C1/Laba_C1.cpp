#include <iostream>
#include <Windows.h>

using namespace std;
HANDLE MyPS4 = GetStdHandle(STD_OUTPUT_HANDLE);
void Input(double* Arr1[], double* Arr2[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j <= i)
                cin >> Arr1[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j <= i)
                cin >> Arr2[i][j];
        }
    }
}
void Output(double* Arr1[], double* Arr2[], int SIZE)
{
    cout << "First Triangle" << endl;
    SetConsoleTextAttribute(MyPS4, 6);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j <= i)
                cout << *(Arr1[i]+j) << " ";
            else
                cout << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(MyPS4, 7);
    cout << "Second Triangle" << endl;
    SetConsoleTextAttribute(MyPS4, 2);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j <= i)
                cout << *(Arr2[i]+j) << " ";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void Multiplication(double* Arr1[], double* Arr2[], double* Mult[], int SIZE)
{
    double a, b;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            Mult[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
            {
                if (k > i)
                {
                    if (j > k)
                    {
                        a = Arr1[k][i];
                        b = Arr2[j][k];
                        Mult[i][j] += a * b;
                    }
                    else
                    {
                        a = Arr1[k][i];
                            Mult[i][j] += a * Arr2[k][j];
                    }
                }
                else
                {
                    if (j > k)
                    {
                        b = Arr2[j][k];
                        Mult[i][j] += Arr1[i][k] * b;
                    }
                    else
                        Mult[i][j] += Arr1[i][k] * Arr2[k][j];
                }
            }
        }
    }
    SetConsoleTextAttribute(MyPS4, 7);
    cout << "The Multiplication of Matrix" << endl;
    SetConsoleTextAttribute(MyPS4, 3);
    for (int i = 0; i < SIZE; i++)
    {
        for (double *j = Mult[i]; j < Mult[i] + SIZE; j++)
        {
            cout << *(j) << " ";
        }
        cout << endl;
    }
}
int main()
{   
    int SIZE;
    cout << "Enter The Size of Array ";
    cin >> SIZE;
    double** Mult = new double* [SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        Mult[i] = new double[SIZE];
    }
    double** Arr1 = new double* [SIZE];
    double** Arr2 = new double* [SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j <= i)
            {
                Arr1[i] = new double[j];
                Arr2[i] = new double[j];
            }
        }
    }
    Input(Arr1, Arr2, SIZE);
    Output(Arr1, Arr2, SIZE);
    Multiplication(Arr1, Arr2, Mult, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        delete Mult[i];
    }
    delete[] Mult;
    Mult = NULL;
    SetConsoleTextAttribute(MyPS4, 7);
  }