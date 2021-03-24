//Монетка

#include <iostream>

int a[100], m, i, n;

using namespace std;

int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
    {
        if (a[i] == m)
        {
            cout << i;
            i = n;
        }
    }
    return 0;
}
