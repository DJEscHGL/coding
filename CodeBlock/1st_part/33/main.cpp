#include <iostream>

using namespace std;

int h, m, i, n, p, k;

int main()
{
    cin >> h >> m;
    n = h * 100 + m + 1;
    while (i != 1)
    {
        if (n >= 2400)
            n = 0;
        if (n % 100 >= 59)
            n = ((n / 100) + 1) * 100;
        p = n / 100;
        k = n % 100;
        k = (k % 10) * 10 + (k / 10);
        if (p == k)
            i = 1;
        else
            n++;
    }
    k = (k % 10) * 10 + (k / 10);
    if(p < 10)
        if (k < 10)
            cout <<"0"<< p << ":"  << "0" << k;
        else
            cout <<"0"<< p << ":" << k;
    else
        if (k > 10)
            cout <<p << ":" << k;
        else
            cout <<p << ":" << "0" << k;
    return 0;
}
