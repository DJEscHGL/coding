#include <iostream>

using namespace std;

int i, k, g, p, l;
int a[105];
int main()
{
    cin >> k;
    for (i = 1; i <= k; i++)
        cin >> a[i];
    for (i = 1; i <= k-2; i++)
        for (g = i+1; g <= k-1; g++)
            for (p = g+1; p <=k; p++)
                {
                    if (a[i] + a[g] > a[p] && a[g] + a[p] > a[i] && a[i] + a[p] > a[g])
                        if (a[g] != a[i] && a[i] != a[p] && a[p] != a[g])
                            l++;
                }
    cout << l;
    return 0;
}
