#include <iostream>

using namespace std;

int main()
{
    int x, y, s;
    s = 0;
    x = 10005;
    while(x < 99999)
    {
        y = x % 10;
        if (y != 0)
        {
            if (x % y == 0)
                s++;
        }
        x += 23;
    }
    cout<<s;
    return 0;
}
