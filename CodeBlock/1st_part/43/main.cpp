#include <iostream>

using namespace std;

int i, j, k, p[100], r[100], d, n, v;

int main()
{
    n = 9;
    for (i = 0; i <= n; i++)
            p[i] = i;
    while (p[0] == 0)
    {
        v++;
        for (i = 1; i <= n; i++)
            cout << p[i];
        cout << endl;
        j = n;
        while (p[j - 1] > p[j])
            j = j - 1;
        k = n;
        while (p[j - 1] > p[k])
            k = k - 1;
        d = p[j - 1];
        p[j - 1] = p[k];
        p[k] = d;
        for (i = j; i <= n; i++)
            r[i] = p[n - (i - j)];
        for (i = j; i <= n; i++)
            p[i] = r[i];
    }
    cout << "VSEGO " << v;
    return 0;
}
