#include <iostream>
#include <cmath>

using namespace std;

int x, y, x2, y2, x3, y3, l;
float k;

int main()
{
    bool line  = false;
    cin >> x >> y;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    l = ((x3 - x) * (y2 - y)) - ((y3 - y) * (x2 - x));
    if (l == 0)
        line = true;
    if (line == true)
        cout << "NO TRIANGLE";
    else
    {
        k = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
        k += sqrt((x - x3) * (x - x3) + (y - y3) * (y - y3));
        k += sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        cout << k;
    }
    return 0;
}
