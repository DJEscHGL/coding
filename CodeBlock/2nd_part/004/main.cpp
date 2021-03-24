#include <iostream>

using namespace std;

int a, b, p, l, n;

int main()
{
    cin >> a >> b;
    l = a;
    n = b;
    while (a != b)
    {
        if (a >= b)
            a = a - b;
        else
            b = b - a;
        if (a == 0)
            p = b;
        else
            p = a;
    }
    cout << p << endl;
    cout << l * n / p;
    return 0;
}
