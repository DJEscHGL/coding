#include <iostream>

using namespace std;

long long p, i, t, k;

int main()
{
    cin >> p;
    i = 1;
    k = p;
    while (t != 2)
    {
        if (k % 10 > 0)
            {
                break;
                t = 2;
            }
        if (k % 10 == 0)
            {
                k = k / 10;
            }

    }
    while (i >= 0)
    {
        if (k < 10)
        {
            cout << k;
            break;
        }
        i = k % 10;
        cout << i;
        k = k / 10;
    }
    return 0;
}
