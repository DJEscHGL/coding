#include <iostream>

using namespace std;

long int a, b, c, n, l;

int main()
{
    cin >> n;
    a = 1;
    l = 1;
    c = 1;
    while (l != n - 1)
    {
        b = c;
        c = a;
        a = c + b;
        l++;
    }
    cout << a;
    return 0;
}
