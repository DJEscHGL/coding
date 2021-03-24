#include <iostream>
#include <fstream>

using namespace std;

int n;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n;
    for(int x1 = 9; x1 > 7; x1--)
        for(int x2 = x1; x2 > x1 - 2; x2--)
            for(int x3 = x2; x3 > x2 - 2; x3--)
                for(int x4 = x3; x4 > x3 - 2; x4--)
                    for(int x5 = x4; x5 > x4 - 2; x5--)
                        for(int x6 = x5; x6 > x5 - 2; x6--)
                            for(int x7 = x6; x7 > x6-2; x7--)
                                for(int x8 = x7; x8 > x7-2; x8--)
                                    for(int x9 = x8; x9 > x8 - 2; x9--)
                                    {
                                        if(x9 == n)
                                            cout <<x1<<x2<<x3<<x4<<x5<<x6<<x7<<x8<<x9<<endl;
                                    }
    return 0;
}
