#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    int x, l, p, i;
    p = 0;
    l = 0;
    i = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> x;
    cout <<"In 2 = "<< x<<endl;
    while (x != 0)
    {
         l = x % 10;
         p += l *pow(2, i);
         i++;
         x /= 10;
    }
    cout <<"In 10 = "<<p;
    return 0;
}
