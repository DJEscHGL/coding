#include <iostream>

using namespace std;

int main()
{
    int a, b, c, min, max;
    cin>>a>>b>>c;
    if (a>b)
    {
        if (a>c)
            if (b>c)
        {
            min = c;
            max = a;
        }
            else
            {
                max = a;
                min = b;
            }
        else
        {
            max = c;
            min = b;
        }
    }
    else
        if (b>c)
    {
        if (c>a)
            {
                max = b;
                min = a;
            }
            else
            {
                max = b;
                min = c;
            }
    }
        else
    {
        max = c;
        min = a;
    }
    cout<<max - min;
    return 0;
}
