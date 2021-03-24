#include <iostream>
#include <cmath>

using namespace std;

int x1, y1, x2, y2, x3, y3, l;
double k;

int main()
{
    bool line  = false;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    l = ((x3 - x1) * (y2 - y1)) - ((y3 - y1) * (x2 - x1));
    if (l == 0)
        line = true;
    if (line == true)
        cout << "NO TRIANGLE";
    else
    {
        k = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        k += sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        k += sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        cout << k;
    )
    return 0;
}
