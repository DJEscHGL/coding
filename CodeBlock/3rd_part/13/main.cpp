#include <iostream>

using namespace std;

int main()
{
    string m="0123456789";
    string s,g;
    int r1,r2,r3;
    getline(cin,s);
    r1=s.size();
    r2=0;
    g="";
    while (r2<r1) {
          r3=0;
                while(r3<10) {
                if (s[r2]==m[r3]){
                    g=g+s[r2];
                }
                else {
                    g=g;
                }
                r3++;
                }

        r2++;
    }
    cout<<g;
    return 0;
}
