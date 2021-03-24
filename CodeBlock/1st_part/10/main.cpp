#include <iostream>

using namespace std;

int main()
{
    int q, w, e, r, t, n, d;
    n = 0;
    q = 1;
    while (q <= 9)
    {
        w = 1;
        while (w <= 9)
        {
            if (q != w)
            {
                e = 1;
                while (e <= 9)
                {
                    if (q != e && e != w)
                    {
                        r = 0;
                        while (r <= 8)
                        {
                            t = e*10 + r;
                            if (t != 78)
                            {
                                n++;
                            }
                            r += 2;
                        }
                    }
                    e += 2;
                }
            }
            w += 2;
        }
        q += 2;
    }
    n *= 25;
    cout<< n;
    return 0;
}
