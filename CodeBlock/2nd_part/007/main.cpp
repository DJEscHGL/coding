#include <iostream>

using namespace std;

int i, n, c, o[1000];

int main()
{
    c = 0;
    cin >> n;
    cout << endl;
    for (i = 1; i != n + 1; i++)
        cin >> o[i];
    cout << endl;
    i = 1;
    while (i <= n + 1)
    {
        if(o[i] > c)
            c = o[i];
        i++;
    }
    cout << c;
    return 0;
}
