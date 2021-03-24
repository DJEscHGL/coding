#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int a[100][100];
string b[100];
int m, n, i, j, k, l, p, r;
string s;

int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
            cin >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> a[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            {
                s = b[j];
                if ((a[i][j] == 0) && (s[j] == 'W'))
                    p++;
                else
                    if (((a[i][j] == 1) && (s[j] == 'W')) || (s[j] == 'B'))
                        p++;
                    else
                        if (((a[i][j] == 2) && (s[j] == 'W')) || (s[j] == 'G'))
                            p++;
                        else
                            if (((a[i][j] == 3) && (s[j] == 'W')) || (s[j] == 'B') || (s[j] == 'G'))
                                p++;
                            else
                                if (((a[i][j] == 4) && (s[j] == 'W')) || (s[j] == 'R'))
                                    p++;
                                else
                                    if (((a[i][j] == 5) && (s[j] == 'W')) || (s[j] == 'R') || (s[j] == 'B'))
                                        p++;
                                    else
                                        if (((a[i][j] == 6) && (s[j] == 'W')) || (s[j] == 'R') || (s[j] == 'G'))
                                            p++;
                                        else
                                            if (((a[i][j] == 7) && (s[j] == 'W')) || (s[j] == 'R') || (s[j] == 'B') || (s[j] == 'G'))
                                                p++;
                                            else
                                                r++;

            }
    if (p == m * n)
        cout << "All Rigth";
    else
        cout << "Very Bad. " << r << " erroros";
    return 0;
}
