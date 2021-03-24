#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string s, w, q[100];
int a[100] , b[100];
int l, i, p, j, o;

int main()
{
    getline(cin, s);
    p = 1;
    s = s + ' ';
    l = s.length();
    b[0] = -1;
    for (i = 1; i <= l; i++)
    {
        if (s[i] == ' ')
        {
            b[p] = i;
            a[p] = b[p] - b[p-1] - 1;
            p++;
        }
    }
    b[0] = -1;
    for (i = 1; i <= p; i++)
    {
        o = b[i-1] + 1;
        w = s.substr(o, a[i]);
        q[i] = w;
    }
    for (i = 1; i <= p - 1; i++)
        for(j = i; j <= p; j++)
        {
            if (a[j] < a[j+1])
            {
                o = a[j];
                a[j] = a[j+1];
                a[j+1] = o;
                w = q[j];
                q[j] = q[j+1];
                q[j+1] = w;
            }

        }
    for (i = p - 1; i >= 1; i--)
        cout << q[i] << " ";
    return 0;
}
