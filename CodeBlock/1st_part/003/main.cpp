#include <cmath>
#include <iostream>

using namespace std;

float X, Y, R, d;
int n, l, i;

int main()
{
    cin >> X >> Y >> R;
    cin >> n;
    int x[100], y[100], r[100];
    for (i = 1; i <= n + 1; i++)
        cin >> x[i] >> y[i] >> r[i];
    for (i = 1; i <= n + 1; i++)
    {
        d = sqrt(pow((X - x[i]), 2) + pow((Y - y[i]), 2));
        if (d < r[i] + R);
            l++;
    }
    cout << l;
    return 0;
}
