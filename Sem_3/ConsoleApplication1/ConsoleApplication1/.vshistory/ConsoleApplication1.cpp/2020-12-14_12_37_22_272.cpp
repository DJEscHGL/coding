#include <iostream>

using namespace std;

class Foo

{

private:


public:
    int i;

    Foo() { cout << "ONE"; }

    void func() const

    {

        i = 1; //

    }

};

int main() {

    Foo ob;

    // your code goes here

    return 0;
}