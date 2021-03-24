#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int x, y, i, s;
    freopen("input.txt", "r", stdin);
    freopen("output.txr", "w", stdout);
    cin >> x;
    cin >> y;
    s = 2;
    while (x != y)
        {
            for (i = 2; i < x; i++)
            {
                if (x % i == 0)
                    s++;
            }
            if (s == 2)
                cout << x;
            x++;
        }
    return 0;
}
