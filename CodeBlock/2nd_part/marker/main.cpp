#include <iostream>
#include <fstream>

using namespace std;

long long int m, n, k, q[50][2], i, y, p, t[10000][10000], v, f;
char w[50];

int paint (long long int j[10000][10000], int h, int e)
{
    int c, g, f;
    for (g = 1; g <= h; g++)
        for (f = 1; f <= e; f++)
            if (j[g][f] == 1)
                c++;
    return c;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> m >> n;
    cin >> k;
    for (i = 1; i <= n; i++)
        for (y = 1; y <= m; y++)
            t[i][y] = 0;

    for (i = 1; i <= k; i++)
    {
        for (y = 1; y <= 2; y++)
            cin >> q[i][y];
        cin >> w[i];
    }
    for (i = 1; i <= k; i++)
    {
        if (w[i] == 'W')
        {
            f = q[i][2];
            for (y = 1; y <= q[i][1]; y++)
                t[f][y] = 1;
        }
        if (w[i] == 'S')
        {
            f = q[i][1];
            for (y = 1; y <= q[i][2]; y++)
                t[y][f] = 1;
        }
        if (w[i] == 'N')
        {
            f = q[i][1];
            for (y = n; y >= q[i][2]; y--)
                t[y][f] = 1;
        }
        if (w[i] == 'E')
        {
            f = q[i][2];
            for (y = q[i][1]; y <= n; y++)
                t[f][y] = 1;
        }
    }
    p = paint (t, n, m);
    cout << p << endl;
    for (i = 1; i <= n; i++)
        {
            for (y = 1; y <= m; y++)
                cout << t[i][y] << " ";
            cout << endl;
        }
    return 0;
}

