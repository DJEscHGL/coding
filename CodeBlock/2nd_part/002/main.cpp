#include <iostream>

using namespace std;

int n, l;

int main()
{
    l = 1;
    cin >> n;
    while (n != 0)
    {
        l = l * n;
        n--;
    }
    cout << l;
    return 0;
}
