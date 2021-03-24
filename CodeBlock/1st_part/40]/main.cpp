#include <iostream>
#include <cmath>

using namespace std;

float a[100][1], r, p;
int x, y, i, k, n, l, j;

int main()
{
    cin >> x >> y;
    cin >> n;
    for (i = 0; i <= n - 1; i++)
        for (j = 0; j <= 1; j++)
            cin >> a[i][j];
    for (i = 0; i <= n - 1; i++)
    {
        cout << endl;
        for (j = 0; j <= 1; j++)
            cout << a[i][j] << " ";
    }
    cout << endl;
    for (i = 0; i <= n - 1; i++)
    {
        l = sqrt((x - a[i][0]) * (x - a[i][0]) + (y - a[i][1]) * (y - a[i][1]));
        if (l > 2)
            k++;
    }
    cout << k;
    return 0;
}
