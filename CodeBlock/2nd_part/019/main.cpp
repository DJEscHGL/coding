#include <iostream>

using namespace std;

int l, p;

void suma(int a, int b, int o)
{
    o = a + b;
    return o;
}

int main()
{
    int c;
    cin >> l >> p;
    c = suma(l, p);
    return 0;
}
