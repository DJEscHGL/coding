#include <iostream>

using namespace std;

int k, i, l;

int main()
{
    cin >> k;
    while (k != 2)
    {
        k -= 4;
        k -= 4;
        cout << k << endl;
        l += k;
    }
    cout << l;
    return 0;
}
