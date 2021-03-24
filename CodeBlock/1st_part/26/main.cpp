#include <iostream>

using namespace std;

int i, n, j, k, v;

int main()
{
    cin >> n;
    int a[n];
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
    cout << "IF From UP to DOWN --- write 1" << endl;
    cout << "IF From DOWN to UP --- write 2" << endl;
    cin >> v;
    if (v == 1)
        for (i = 1; i <= n; i++)
            cout << a[i] << " ";
        else
            if (v == 2) for (i = n; i >= 1; i--)
                cout << a[i] << " ";
    return 0;
}
