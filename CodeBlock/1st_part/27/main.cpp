#include <iostream>
#include <string>

using namespace std;

int a[100][100];
string b[100];
int m, n, i, j, k, l, p;
string s;

int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> a[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            {
                s = b[j];
                if (a[i][j] == 0 && b[j] == 'W')
                    p++;
                else
                    if ((a[i][j] == 1) && (b[j] == 'W' || b[j] == 'B'))
                        p++;
                    else
                        if ((a[i][j] == 2) && (b[j] == 'W' || b[j] == 'G'))
                            p++;
                        else
                            if ((a[i][j] == 3) && (b[j] == 'W' || b[j] == 'B' || b[j] == 'G'))
                                p++;
                            else
                                if ((a[i][j] == 4) && (b[j] == 'W' || b[j] == 'R'))
                                    p++;
                                else
                                    if ((a[i][j] == 5) && (b[j] == 'W' || b[j] == 'R' || b[j] == 'B'))
                                        p++;
                                    else
                                        if ((a[i][j] == 6) && (b[j] == 'W' || b[j] == 'R' || b[j] == 'G'))
                                            p++;
                                        else
                                            if ((a[i][j] == 7) && (b[j] == 'W' || b[j] == 'R' || b[j] == 'B' || b[j] == 'G'))
                                                p++;
            }
    if (p == m * n)
        cout << "All Rigth";
    else
        cout << "Very Bad";
    return 0;
}
