#include <iostream>
#include <locale>
#include <Windows.h>

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

istream& operator>> (istream& in, Complex& num) {
	cout << "Целая часть числа: ";
	in >> num.a;
	cout << "Мнимая часть числа: ";
	in >> num.b;
	return in;
}

ostream& operator<< (ostream& out, Complex& num) {
	if (num.b < 0)
		out << num.a << num.b << "i" << endl;
	else
	{
		if (num.b != 0)
			out << num.a << "+" << "i" << endl;
		else
			out << num.a << "+" << num.b << "i" << endl;
	}
	return out;
}

class ComplexVector {
public:
	int n;
	Complex** vector;
	ComplexVector(int nn) {
		n = nn;
		vector = new Complex*[n];
		for (int i = 0; i < n; i++) {
			vector[i] = new Complex;
			cin >> *vector[i];
		}
	}
	void Out() {
		for (int i = 0; i < n; i++) {
			cout << *vector[i];
		}
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num, n;
	cout << "Введите количество векторов: ";
	cin >> num;
	auto Vectors = new ComplexVector*[num];
	for (int i = 0; i < num; i++) {
		cout << "Введите размерность вектора: ";
		cin >> n;
		Vectors[i] = new ComplexVector(n);
	}
}