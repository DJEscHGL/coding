#include <iostream>

using namespace std;

int b[50];
int k, m, a, c, d, r, p, g;
int main()
{
    cin >> k;
    cin >> m;
    a = 0;
    c = k;
    b[1]=k;
    d = 1;
    for (int i = 1; i <= m; i++)
    {
        p = 0;
        for (int g = 1; g <= d; g++)
        {
            r = a + c + p;
            b[i] = r % 10;
            p = r / 10;
             if (p == 1)
                {
                d++;
                b[d] = 1;
                }

        }
        a = c;
        c = b[i];
        cout<< b[i]<< " ";
    }
   // for (i = 0; i <= d; i++)
        //cout<< c;
    return 0;
}
