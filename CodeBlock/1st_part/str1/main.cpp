#include <iostream>

using namespace std;
int n;
string s;
int main()
{

	ostringstream ss;
	n=123;
	ss<<n;
	s=ss.str();

    cout << s;
    return 0;
}
