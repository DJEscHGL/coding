#include <iostream>

using namespace std;

int main()
{   string s1,s2,s3;
    int a,b,c,d,g,r1,r2,r3;
    getline(cin,s1);
    getline(cin,s2);
    a=s1.size();
    b=s2.size();
    c=0;
    g=0;
    while ( c<a ) {
       d=0;
       while ( d<b ) {
                 if( s1[c]==s2[d] ) {
                    s3[g]=s1[c];
                    cout<<s1[c];
                                 }

                    d++;
                    g++;
       }
       c++;
    }
    r1=0;

     while ( r1<g )
        { r3=0;
            while(r3<g)  {if ( s3[r1]==s3[r3] && r1!=r3 )
                {

                       s3=s3.erase(r3,1);


                }
               r3++;
             }
 r1++;
    }
           r2=0;
           while (r2<g) {cout<<s3[r2]; r2++;}    return 0;}


