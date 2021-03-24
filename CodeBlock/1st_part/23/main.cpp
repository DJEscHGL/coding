#include <iostream>

using namespace std;

int m, n, p, b, x, y;

int main()
{
    long a;
    p = 2;
    b = 2;
    cin >> a;
    m = a;
    n = 0;
    while (m >= a / 2)
    {
        if (n != 1)
        {
            b = 2;
            p = 2;
            while (b <= m / 2)
            {
                if (m % b == 0)
                    p++;
                b++;
            }
            if (p == 2)
                {
                    n = 1;
                    x = m;
                }
        }
        m--;
    }
    m = a;
    n = 0;
    while (m <= a * 2)
    {
        if (n != 1)
        {
            b = 2;
            p = 2;
            while (b <= m / 2)
            {
                if (m % b == 0)
                    p++;
                b++;
            }
            if (b == 2)
            {
                n = 1;
                y = m;
            }
        }
        m++;
    }
    if (a - x > y - a)
        cout << y;
    else
        cout << x;
    return 0;
}
