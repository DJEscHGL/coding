#include <iostream>
#include <cmath>

using namespace std;

float a[10], b[10], l;
int x, y, i, k;

int main()
{
    cin >> x >> y;
    for (i = 1; i <= 10; i++)
        cin >> a[i] >> b[i];
    for (i = 1; i <= 10; i++)
    {
        l = sqrt((x - a[i]) * (x - a[i]) + (y - b[i]) * (y - b[i]));
        if (l <= 30)
            k++;
    }
    if (k > 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
