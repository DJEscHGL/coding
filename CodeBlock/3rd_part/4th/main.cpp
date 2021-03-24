#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
    string a[80];
    int i, l, k = 0;
    string s;
    getline(cin, s);
    i = s.find(' ');
    s.incert(i, a[1]);
    return 0;
}
