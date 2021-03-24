#include <iostream>

using namespace std;

int k, c[20], i, j, o, s;

int main()
{
    cin >> k;
    for (i = 1; i <= k * 2; i++)
        cin >> c[i];
    for (i = 1; i <= k * 2; i++)
    {
        for (j = i; j <= k * 2; j++)
        {
            if (c[j] > c[i])
            {
                o = c[j];
                c[j] = c[i];
                c[i] = o;
            }
        }
    }
    for (i = 1; i <= k * 2; i += 2)
        s += c[i] * c[i + 1];
    cout << s;
    return 0;
}
