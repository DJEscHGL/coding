//#¹ 1 p 16
#include <iostream>

using namespace std;

int a, b, c, l, p, m;
int main()
{
    cin >> a >> b >> c;
    l = b - a;
    p = c - b;
    if (l == p)
    {
        if (l == 1 && a == 1 || a == 4 || a == 7)
            m = 1;
        if (l == 3)
            m = 1;
        if (l == 4)
            m = 1;
        if (l == 2 && a == 3)
            m = 1;
    }
    if (m == 1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
