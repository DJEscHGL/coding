#include <iostream>

using namespace std;

int b[50];
int k, m, a, c, d, r, p, g;
int main()
{
    cin >> k;
    cin >> m;
    a = 0;
    c = k;

    d = 1;
    for (int i = 1; i <= m; i++)
    {

            r = a + c ;



        a = c;
        c = r;
        cout<< c<< " ";
    }
   // for (i = 0; i <= d; i++)
        //cout<< c;
    return 0;
}

