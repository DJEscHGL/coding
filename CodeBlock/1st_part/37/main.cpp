#include <iostream>
#include <fstream>

using namespace std;
int i, l, k, n, m, b;

int main()
{
    freopen("pole.txt", "r", stdin);
    freopen("ygl.txt", "w", stdout);
    cin >> m >> b;
    int a[m][b];
    for (i = 0; i <= m; i++)
        for (l = 0; l <= b; l++)
            cin >> a[m][b];
    for (i = 1; i <= m - 1; i++)
        for (l = 1; l <= b - 1; l++)
        {
            if (a[i][l] == 1)
                k++;
            cout << k << endl;
        }
    cout << k << endl;
    n = k * 4;
    cout << n << endl;
    for (i = 1; i <= m - 1; i++)
        for (l = 1; l <= b - 1; l++)
        {
            if (a[i][l] == a[i][l+1] && a[i][l] == a[i+1][l] && a[i][l] == a[i+1][l+1])
                k -= 12;
            else
                if (a[i][l] == a[i][l+1] && a[i][l] == a[i+1][l])
                    k -= 6;
                else
                    if (a[i][l] == a[i][l+1])
                        k -= 4;
                    else
                        if (a[i][l] == a[i+1][l])
                            k -= 4;
        }
    cout << k;
    return 0;
}
