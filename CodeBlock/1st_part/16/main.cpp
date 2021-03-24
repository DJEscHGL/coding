#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    int l, i, n, p;
    p = 0;
    n = 0;
    string s, m;
    cin >> s;
    l = s.length();
    for (i = 0; i != l; i++)
    {
        if (s[i] == 'A')
            p += 10 * pow(16, l-i-1);
        else
        {
            if (s[i] == 'B')
                p += 11 * pow(16, l-i-1);
            else
            {
                if (s[i] == 'C')
                    p += 12 * pow(16, l-i-1);
                else
                {
                    if (s[i] == 'D')
                        p += 13 * pow(16, l-i-1);
                    else
                    {
                        if (s[i] == 'E')
                            p += 14 * pow(16, l-i-1);
                        else
                        {
                            if (s[i] == 'F')
                                p += 15 * pow(16, l-i-1);
                            else
                            {
                                m[0] = s[i];
                                n = atoi(m.c_str());
                                p += n * pow(16, l-i-1);
                            }
                        }
                    }
                }
            }
        }
    }
    if (p % 5 == 0)
        cout << "YES";
    else
        cout << "NO " << p % 5;
    return 0;
}
