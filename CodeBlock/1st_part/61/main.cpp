#include <iostream>

using namespace std;

int k, kol, l, a, b, c, d;

int main()
{
    a = 1;
    b = 1;
    c = 1;
    cin >> k;
    l = k;
    d = k - 3;
    if (k < 4 )
        kol = 0;
    else
    {
        while (c <= d)
        {
            c++;
            d--;
            cout << a << "+" << b << "+" << c << "+" << d <<endl;
            kol++;
        }
        while (b <= c && c <= d)
        {
            c--;
            b++;
            cout << a << "+" << b << "+" << c << "+" << d <<endl;
            kol++;
        }
        while (a <= b && c <= d && b <= c)
        {
            c--;
            b++;
            d--;
            b--;
            cout << a << "+" << b << "+" << c << "+" << d <<endl;
            kol++;
        }
    }
    cout << kol;
    return 0;
}
