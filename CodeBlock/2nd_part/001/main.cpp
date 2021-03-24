#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

long int a, b, n, l;

int main()
{
    cin >> a >> n;
    b = 1;
    for (l = 1; l <= n; l++)
    {
        b = b * a;
    }
    cout << b;
    return 0;
}
