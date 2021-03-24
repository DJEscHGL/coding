#include <iostream>

using namespace std;

int main()
{
    int a, p, i, l, c, d;
    cin>>a;
    i = a%10;
    p = a/10;
    l = p%10;
    p = a/100;
    c = p%10;
    p = a/1000;
    d = p;
    if (i == d && l == c)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
