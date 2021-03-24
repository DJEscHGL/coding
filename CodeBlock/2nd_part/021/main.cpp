#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string s, b;
int i, o, n, k, t;

int main()
{
    i = 0;
    o = 0;
    b = "aeiuyo";
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    getline(cin, s);
    while (i != 1)
    {
        if (b.find(s[o]) != 1)
            i = 1;
        else
            o++;
    }
    i = o + 1;
    n = o;
    t = b.find(s[o]);
    while(s[i] != b[t])
        i++;
    k = i;

    return 0;
}
