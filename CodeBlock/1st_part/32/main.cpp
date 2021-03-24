#include <iostream>

using namespace std;

string s;
string n = "gvbdjz";
string p = "kfpthc";
int i, l, x, j;

int main()
{
    getline(cin, s);
    l = s.length();
    for (i = 0; i <= l; i++)
    {
        for (j = 0; j <= 5; j++)
        {
            x = s.find(p[j]);
            if (x != -1)
                s[x] = n[j];
            x = s.find(n[j]);
            if (x != -1)
                s[x] = p[j];
        }
    }
    cout << s;
    return 0;
}
