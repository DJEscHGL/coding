#include <iostream>

using namespace std;

int main()
{
    double a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if ((a < x && b < y) || (a < y && b < x))
        cout << "Yes";
    else
        if ((b < x && c < y) || (b < y && c < x))
            cout << "Yes";
        else
            if ((c < x && a < y) || (c < y && a < x))
                cout << "Yes";
            else
                cout << "No";
    return 0;
}
