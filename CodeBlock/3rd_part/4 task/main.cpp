#include <iostream>

using namespace std;

int main()
{
    string a[85];
    int q, i, h, l, k, j, K, u = 0;
    int m[85];
    string s, p;
    getline(cin, s);
    s = s + ' ';
    q = s.length();
    while (h <= q)
        {
            k = i;
            i = s.find(' ');
            h= i;
            a[l] = s.substr(k, i-1);
            l++;
        }
    l = 0;
    while (l <= 85)
        {
            p = a[l];
            m[l] = p.length();
            l++;
        }
    l = 0;
    while (l <= 85)
        {
            cout<<m[l]<<" ";
            l++;
        }
    return 0;
}
