#include <iostream>

using namespace std;

int main()
{
    int q, w, e, r, t, u, i, o, p, a, l;
    l = 0;
    for (q = 0; q <= 2; q++)
    {
        u = 100 - q * 50;
        for (w = 0; w<= 4; w++)
        {
            i = u - w * 25;
            for (e = 0; e <= 10; e++)
            {
                o = i - e * 10;
                for (r  = 0; r <= 20; r++)
                {
                    p = o - r * 5;
                    for (t = 0; t <= 50; t++)
                    {
                        a = p - t * 2;
                        l++;
                    }
                }
            }
        }
    }
    cout << l;
    return 0;
}
