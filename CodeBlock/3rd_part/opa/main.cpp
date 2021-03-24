#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    string s, o;
    int a, i, l, p;
    cin >> s;
    l = 0;
    a = 0;
    i = s.length();
    while(l != i)
        {
            o = s[l];
            p = atoi(o.c_str());
            if (p % 2 == 0 && p != 0)
                {
                    a++;
                }
            l++;
        }
    cout <<a;
    return 0;
}
