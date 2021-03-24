#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, x, y, l, k,z;
    char a[12];
    string s, p;
    cin >> x >>y;



    if (x==1)
        x++;
  for (int z=x; z<=y;z++ )


       {
           i = 0;
           k = 2;
           p="";
            itoa(z, a, 10);
            s = a;
            l = s.length();
            while (i != l)
                {
                    p = s[i] + p;
                    i++;
                }
            i = 2;
            while (i <= z/2)
                {
                    if (z % i == 0)
                        k++;
                    i++;
                }
            if (k == 2 && s == p)
                cout<< z <<" -- prostoi palindrom v dannom rady;  "<<endl;

        }
    return 0;
}
