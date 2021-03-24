#include <iostream>
#include <cmath>

double a[9], z, s, b, sum;
int i, n;

using namespace std;

int main()
{
    cin >> n;
    for (i = 0; i != n; i++)
        cin >> a[i];
    s = a[0];
    b = a[0];
    for (i = 0; i != n; i++)
        sum += a[i];
    for (i = 0; i != n; i++)
    {
        if (a[i] >= b)
            b = a[i];
        if (a[i] <= s)
            s = a[i];
    }
    sum -= (s + b);
    z = sum / (n - 2);
    cout << round(z * 10)/10;
    return 0;
}
