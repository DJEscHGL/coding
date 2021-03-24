#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int x, i, p, l;
    i = 0;
    p = 0;
    l = 1;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> x;
    cout << "In 10 = "<<x<<endl;
    while (x > 0)
    {
        i = x % 2;
        p += i * l;
        x /= 2;
        l *= 10;
    }
    cout << "In 2 = "<<p;
    return 0;
}
