#include <iostream>

using namespace std;

class Complex {
public:
	int a, b; 
	void Summing(Complex fst, Complex snd) {
		a = fst.a + snd.a;
		b = snd.b + snd.b;
	}
	void Multiplication(Complex fst, Complex snd) {
		a = fst.a * snd.a - fst.b * snd.b;
		b = fst.a * snd.a + fst.b * snd.b;
	}
	Complex operator= (Complex obj) {
		a = obj.a;
		b = obj.b;
		return *this;
	}
};

Complex operator+ (Complex num1, Complex num2) {
	Complex result;
	result.Summing(num1, num2);
	return result;
}

Complex operator* (Complex num1, Complex num2) {
	Complex result;
	result.Multiplication(num1, num2);
	return result;
}

istream operator>> (ostream& out, Complex num) {
}

ostream operator<< (ostream& out, Complex num) {
	if (num.b < 0)
		out << num.a << num.b << "i";
	else if (num.b != 0)
		out << num.a << "+" << "i";
	else
		out << num.a << "+" << num.b << "i";
}

int main() {

}