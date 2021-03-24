#include <iostream>

using namespace std;

int i, n, p, o[1000];

int main()
{
    cin >> n;
    for(i = 1; i != n + 1; i++)
        cin >> o[i];
    i = 1;
    while (i != n + 1)
    {
        if (o[i] != o[i + 1])
            p++;
        i++;
    }
    cout << p;
    return 0;
}
