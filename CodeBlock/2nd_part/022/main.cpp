#include <iostream>

using namespace std;

int i, k, c, t;

int main()
{
    t = 1;
    c = 1;
    i = 1;
    cin >> k;
    for(i = 1; i != k; i++)
    {
        if (c == t)
            t++;
        c++;
    }
    cout << t;
    return 0;
}
