#include <iostream>

using namespace std;

int N, C[100], i, s, l, p;

int main()
{
    cin >> N;
    for (i = 1; i != N + 1; i++)
        cin >> C[i];
    l = 0;
    while (l < N + 1)
    {
        p = l;
        l++;
        for (i = l; i < N + 1; i++)
        {
            if (C[i] > C[l])
                l = i;
        }
        s += (l - p) * C[l];
    }
    cout << s;
    return 0;
}
