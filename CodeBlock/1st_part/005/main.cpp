#include <iostream>

using namespace std;

int k, a, b, s, p, o;

int main()
{
    cin >> k >> a >> b;
    p = k / (a + b);
    s = p * 2;
    p = k % (a + b);
    if (p < a || p < b)
        s++;
    else
    {
        if (a < b)
        {
            o = a;
            a = b;
            b = o;
        }
        while (p >= 0)
        {
            p -= a;
            s++;
        }
    }
    cout << s;
    return 0;
}
