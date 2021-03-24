#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int x, y, i, n;
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> x;
    cin >> y;
    i = x * y;
    if (x == y){
        cout << "NOD = " <<y;
        n = x;
    }
    if (x == 0){
        cout << "NOD = " <<y;
        n = y;
    }
    if (y == 0){
        cout << "NOD = " <<x;
        n = x;
    }
    if (x > y)
        {
            while (x != y)
                {
                    if (x > y)
                        x = x - y;
                    else
                        y = y - x;
                }
            cout << "NOD = " <<x;
            n = x;
        }
        else
            {
                while (y != x)
                    {
                        if (x > y)
                            x = x - y;
                        else
                            y = y - x;
                    }
                cout << "NOD = " <<y;
                n = y;
            }
    cout <<"  NOK = " <<i/n;
    return 0;
}
