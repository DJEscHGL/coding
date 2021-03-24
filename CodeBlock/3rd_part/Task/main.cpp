#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(0, "");
    string s, d, f;
    int i, l, r, k, m, y = 0;
    getline(cin, s);
    l = s.length();
    s = ' ' + s + ' ';
    d = ' ';
    while (i != l)
        {
            k = r;
            r = s.find(' ');
            d = s.substr(k + 1, r - 1);
            m = d.length();
            while (m != 0)
            {
                    f +=d[m];
                    m--;
            }
            m = d.length();
            while (m != 0)
            {
                if (f[m] == d[m])
                    y++;
            }
            if(m == y)
                    cout<<"Полиндром "<<d;
            i = r;
        }
    return 0;
}
