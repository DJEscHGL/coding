#include <iostream>

using namespace std;

class Complex {
public:
	int a, b; 
	void Summing(Complex fst, Complex snd) {
		a = fst.a + snd.a;
		b = snd.b + snd.b;
	}
	Complex operator= (Complex obj) {
		a = obj.a;
		b = obj.b;
		return *this;
	}
};

Complex operator+ (Complex num1, Complex num2) {

}

Complex operator* (Complex num1, Complex num2) {

}

istream operator>> (Complex num1, Complex num2) {

}

ostream operator<< (Complex num1, Complex num2) {

}

int main() {

}