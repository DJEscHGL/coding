#include <iostream>

using namespace std;

int main()
{
    int i, l, k;
    string a;
    l = 0;
    cin>>a;
    k = a.length();
    for (i = 0; i<=k; i++)
        {
            if (a[i] == '6' || a[i] == '9' || a[i] == '0')
                l++;
            if (a[i] == '8')
                l = l+2;
        }
    cout<<l;
    return 0;
}
