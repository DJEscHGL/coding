#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int x, i, k,  y, r, l;
    k = 2;
    y = 0;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x;
    l = 2*x;
    if (x % 2 == 0)
        x++;
    while (x <= l)
    {
        r = y;
        while (i <= x / 2)
        {
            if (x % i == 0)
                k++;
            i++;
        }
        if (k == 2)
            y = x;
        if (y - r == 2)
            cout<<r<<" and "<<y<<" bliznetc"<<endl;
        x = x + 2;
    }
    return 0;
}
