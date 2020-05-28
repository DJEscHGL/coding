#include<iostream>

using namespace std;

int main()
{
    union TUI
    {
        struct {
            unsigned n1 : 4;
            unsigned n2 : 4;
        }   num16;
        short int ch;
    }    N;
    cin >> N.ch;
    cout << hex << N.num16.n2 << N.num16.n1;

    return 0;
}