#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, d, n, p, l;
    n = 0;
    cin >> a >> b;
    if (a == b)
        cout << " вадрат";
    else
    {
        if (a < b)
        {
            c = b;
            d = a;
        }
        else
        {
            c = a;
            d = b;
        }
    }
    while (c * d != 0)
    {
        p = c / d;
        c = c % d;
        l = c;
        c = d;
        d = l;
        n += p;
    }
    cout << n;
    return 0;
}
