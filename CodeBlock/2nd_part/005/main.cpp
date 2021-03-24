#include <iostream>

using namespace std;

int a, b, c, n;

int main()
{
    cin >> b >> n;
    c = 1;
    while (a != b)
    {
        cout << 10 * c / n;
        c = 10 * c % n;
        a++;
    }
    return 0;
}
