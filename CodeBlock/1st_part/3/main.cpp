#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, x, y, l, k, z, v;
    char a[12];
    v = 0;
    string s, p;
    cin >> x >>y;
    if (x == 1)
        x++;
    for (z = x; z <= y; z++)
       {
            if (z == 2)
                {
                    cout<<z<<" -- prostoi polindrom"<<endl;
                    v++;
                }
            if (z % 2 == 0)
                z++;
            k = 2;
            p = "";
            i = 0;
            itoa(z, a, 10);
            s = a;
            l = s.length();
            while (i != l)
                {
                    p = s[i] + p;
                    i++;
                }
            i = 2;
            while (i <= z/2)
                {
                    if (z % i == 0)
                        k++;
                    i++;
                }
            if (k == 2 && s == p)
                {
                    v++;
                    cout<<z<<" -- prostoi polindrom"<<endl;
                }
        }
    cout<<"vsego "<<v;
    return 0;
}
