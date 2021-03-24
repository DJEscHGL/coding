#include <iostream>

using namespace std;

int l, n, t, v, k, p;

int main()
{
    cin >> l;
    cin >> n;
    cin >> v;
    cin >> t;
    k = l / n;
    cout << k << endl;
    p = v * t;
    cout <<p / k;
    return 0;
}
