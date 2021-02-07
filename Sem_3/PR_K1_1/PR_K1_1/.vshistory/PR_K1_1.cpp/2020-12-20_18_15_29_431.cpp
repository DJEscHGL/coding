#include <iostream>

using namespace std;

class Complex {
public:
	int a, b; 
	void Out() {
		if(b < 0)
			cout << a << b << "i" << endl;
		else
			cout << a << "+" << b << "i" << endl;
	}
	void Summing(Complex fst, Complex snd) {
		a = fst.a + snd.a;
		b = snd.b + snd.b;
	}
};

int main() {

}