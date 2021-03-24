//Сортировка пузырьком

#include <iostream>

using namespace std;

int a[100], i, o, p, n, y;

int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
    {
        for(y = 1; y <= n - i; y++)
        {
            if (a[y] <= a[y + 1])
            {
                o = a[y];
                p = a[y + 1];
                a[y] = p;
                a[y + 1] = o;
            }
        }
    }
    for (i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
