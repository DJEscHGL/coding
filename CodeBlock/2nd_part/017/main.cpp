#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

string s, o;
unsigned long long int n, p, m, k, i;

int main()
{
    n = 0;
    p = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    getline(cin, s);
    n = atoi(s.c_str());
    m = s.size();
    for(i = 0; i != m; i++)
    {
        o = s[i];
        k = atoi(o.c_str());
        p += k;
    }
    if (p % 3 == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
