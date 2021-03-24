#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string s, d[1000], g, h;
int n, i, p, k, m, l, j[1000], o, b;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    getline(cin, s);
    n = s.size();
    i = 1;
    k = 0;
    p = 0;
    s += " ";
    while (s.find(" ") != -1)
    {
        p = s.find(" ");
        d[i] = s.substr(k, p + 1);
        s.erase(k, p + 1);
        i++;
    }
    for (m = 1; m != i; m++)
        j[m] = d[m].size();
    for (m = 1; m != i; m++)
    {
        for(l = 1; l != i - m; l++)
        {
            if (j[l] < j[l + 1])
            {
                o = j[l];
                b = j[l + 1];
                j[l] = b;
                j[l + 1] = o;
                g = d[l];
                h = d[l + 1];
                d[l] = h;
                d[l + 1] = g;
            }
        }
    }
    for (m = 1; m != i; m++)
        cout << d[m];
    return 0;
}
