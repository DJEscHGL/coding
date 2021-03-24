#include <iostream>
#include <string>

using namespace std;

int
n, i, j, k, l;

int main()
{
    i = 1;
    cin >> n;
    string a [10];
    int p [10], r[11];
    while (i <= n)
    {
        cin >> a[i];
        i++;
    }
    for (i = 0; i != n; i++)
        p [i] = i;
    while (p[0] == 0)
    {
        for (i = 0; i <= n; i++)
            cout <<a[p[i]] << " ";
        j = n;
        cout << endl;
        while (p[j - 1] > p[j])
            j--;
        k = n;
        while (p[j - 1] > p[k])
            k--;
        l = p[j - 1];
        p[j - 1] = p[k];
        p[k] = l;
        for (i = j; i <= n; i++)
            r[i] = p[n - (i - j)];
        for (i = j; i <= n; i++)
            p[i] = r[i];
    }
    return 0;
}
