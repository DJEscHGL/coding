#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int x, i ,o, y, p, l;
    i = 0;
    o = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> x;
    y = x;
    l = x;
    while (x != 0)
    {
        x /= 10;
        i++;
    }
    while (y != 0)
    {
        p = y % 10;
        o += pow(p, i);
        y /= 10;
    }
    if (l == o)
        cout<<"Strong";
    else
        cout<<"Not strong";
    return 0;
}
