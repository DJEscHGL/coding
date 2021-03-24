#include <iostream>

using namespace std;

double n, x, z, s, y;

int main()
{
    x = 1;
    z = 1;
    cin >> n;
    while (x != n + 1)
    {
        z = z * x;
        y = 1 / z;
        s = s + y;
        x++;
    }
    cout << s;
    return 0;
}
