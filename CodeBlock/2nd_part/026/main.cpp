#include <iostream>
#include <cstdio>
#include <queue>
#include <fstream>

using namespace std;

int n, a[30][30], i, j, l, x, y;
queue <int> x1, y1;

int main()
{
    l = 0;
    setlocale(0, "");
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    x1.push (n / 2 + 1);
    y1.push (n / 2 + 1);
    while (!x1.empty())
    {
        x = x1.front();
        y = y1.front();
        x1.pop();
        y1.pop();
        a[x][y] = 1;
        if ((x == 1) || (x == n) || (y == 1) || (y == n))
            l++;
        if (a[x + 1][y] == 0)
        {
            x1.push(x + 1);
            y1.push(y);
        }
        if (a[x][y + 1] == 0)
        {
            x1.push(x);
            y1.push(y + 1);
        }
        if (a[x - 1][y] == 0)
        {
            x1.push(x - 1);
            y1.push(y);
        }
        if (a[x][y - 1] == 0)
        {
            x1.push(x);
            y1.push(y-1);
        }
    }
    if (l == 0)
        cout << "Нет выхода!";
    else
        cout << l;
    return 0;
}
