#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int x, y, i, p, l;
    i = 1;
    p = 0;
    l = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> x;
    cin >> y;
    while (i != x - 1)
    {
        if (x % i == 0)
            p += i;
        i++;
    }
    i = 1;
    while (i != y - 1)
    {
        if (y % i == 0)
            l += i;
        i++;
    }
    if (p == y && l == x)
        cout<<"Friendly";
    else
        cout<<"Unfriendly";
    return 0;
}
