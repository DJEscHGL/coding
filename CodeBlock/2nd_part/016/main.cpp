#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

string s;
unsigned long long int n;

int main()
{
    n = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    getline(cin, s);
    n = atoi(s.c_str());
    cout << n;
    return 0;
}
