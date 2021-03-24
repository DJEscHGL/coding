#include <iostream>

using namespace std;

int r, n, i, c, k, s, p, t, a[1000], b[1000];

int main()
{
    k = 1;
    p = 1000;
    cin >> r >> n >> c;
    for (i = 1; i <= n; i++)
        cin >> a[i] >> b [i];
    for (i = 1; i <= n; i++)
    {
        if (a[i] >= 2 * r && b[i] >= 2 * r)
            {
                s = a[i] * b[i];
                if (s <= p)
                    {
                        p = s;
                        t = i;
                    }
            }
    }
    cout << t << "   "<< p * c;
    return 0;
}
