#include <iostream>

using namespace std;

int main()
{
    int a, i, l, p;
    cin>>a;
    i = a%10;
    p = a/10;
    i = i+p%10;
    p = a/100;
    i = i+p%10;
    p = a/1000;
    l = p%10;
    p = a/10000;
    l = l+p%10;
    p = a/100000;
    l = l+p%10;
    l = l+p/10;
    if (i==l)
        cout<<"YES";
        else cout<<"NO";
    return 0;
}
