#include <iostream>

using namespace std;

class MyClass {
	int b;
	MyClass(int a) {
		b = a;
	}
};

int main() {
	MyClass a[3] = { 1,2,3 };
}