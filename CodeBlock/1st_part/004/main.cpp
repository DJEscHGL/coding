#include <cmath>
#include <iostream>

using namespace std;

int n, s, a, b, c;


int main()
{
    a = 1;
    b = 1;
    cin >> n;
    while (c <= n)
    {
        c = a + b;
        a = b;
        b = c;
        s++;
    }
    cout << s + 1;
    return 0;
}
