#include <iostream>

using namespace std;

int i, j, n, p, k;
char a[3][3];

void pole()
{
        for (i = 1; i <= 3; i++)
        {
            cout << endl;
            for (j = 1; j <= 3; j++)
                cout << a[i][j] << " ";
        }
}

int check_pole ()
{
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++)
        {
            if (a[i][j] == 'x' || a[i][j] == '0')
                n++;
        }
    if (n == 9)
        return 1;
    else
        return 2;
}

int main()
{
    setlocale(0, "");
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++)
            a[i][j] = '_';
    for (i = 1; i <= 3; i++)
        {
            cout << endl;
            for (j = 1; j <= 3; j++)
                cout << a[i][j] << " ";
        }
    cout << endl;
    while (check_pole() != 1)
    {
        cout << "Ходит игрок 1" << endl;
        cin >> p >> k;

    }
    return 0;
}
