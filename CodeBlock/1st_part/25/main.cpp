#include <iostream>

using namespace std;

float x, y, x1, y1, x2, y2, x3, y3;
float A1, A2, B1, B2, C1, C2, P1, P2;
float q, w;

int main()
{
    cin >> x >> y; // сфетофор 1
    cin >> x1 >> y1; // сфетофор 2
    cin >> x2 >> y2; // хутор
    cin >> x3 >> y3; // магазин
    A1 = y1 - y;                // A1
    B1 = x - x1;                // B1
    C1 = (x * y1) - (x1 * y);   // C1
    A2 = y3 - y2;               // A2
    B2 = x2 - x3;               // B2
    C2 = (x2 * y3) - (x3 * y2); // C2
    P1 = (x2 - x) * (y1 - y) - (x1 - x) * (y2 - y);
    P2 = (x3 - x) * (y1 - y) - (x1 - x) * (y3 - y);
    if (P1 * P2 > 0)
        cout << "NO";
    else
    {
        w = ((A1 * C2) - (A2 * C1)) / ((A1 * B2) - (A2 * B1));
        if (A1 != 0)
            q = ((B2 * C1) - (B1 * C2)) / ((A1 * B2) - (A2 * B1));
        else
            w = (C2 - B2 * q) / A2;
        cout << "YES" << endl;
        cout <<q << " " << w;
    }
    return 0;
}
