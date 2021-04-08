#include <iostream>

using namespace std;

class Fraction {
public:
	int numerator, denominator;
	Fraction() {
		cout << "Введите числитель: ";
		cin >> numerator;
		while (true) {
			cout << "Введите знаменатель: ";
			cin >> denominator;
			if (denominator == 0)
				cout << "Знаменатель не должен быть 0!";
			else
				break;
		}
	}
	Fraction(bool temp) {
		numerator = 0;
		denominator = 0;
	}
	void Output() {
		cout << numerator << " / " << denominator << endl;
	}
	void Reduce(){
		int a = numerator, b = denominator;
		while (a != b) {
			if (a > b) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			b = b - a;
		}
		numerator /= a;
		denominator /= a;
	}
	Fraction operator= (Fraction obj) {
		numerator = obj.numerator;
		denominator = obj.denominator;
		return *this;
	}
	Fraction operator+ (Fraction obj) {
		int temp;
		if (denominator == obj.denominator)
			numerator += obj.numerator;
		else {
			int a = denominator, b = obj.denominator;
			temp = a * b;
			while (a != b) {
				if (a > b) {
					int tmp = a;
					a = b;
					b = tmp;
				}
				b = b - a;
			}
			temp /= a;
			numerator *= temp / denominator;
			obj.numerator *= temp / obj.denominator;
			numerator += obj.numerator;
			denominator = temp;
		}
		return *this;
	}
	Fraction operator- (Fraction obj) {
		int temp;
		if (denominator == obj.denominator)
			numerator -= obj.numerator;
		else {
			int a = denominator, b = obj.denominator;
			temp = a * b;
			while (a != b) {
				if (a > b) {
					int tmp = a;
					a = b;
					b = tmp;
				}
				b = b - a;
			}
			temp /= a;
			numerator *= temp / denominator;
			obj.numerator *= temp / obj.denominator;
			numerator -= obj.numerator;
			denominator = temp;
		}
		return *this;
	}
	Fraction operator* (Fraction obj) {
		numerator *= obj.numerator;
		denominator *= obj.denominator;
		return *this;
	}
	Fraction operator/ (Fraction obj) {
		numerator *= obj.denominator;
		denominator *= obj.numerator;
		return *this;
	}
};

int main() {
	setlocale(0, "");
	Fraction first, second;
	Fraction result(true);
	cout << "\nСумма двух дробей:\n";
	result = first + second;
	result.Output();
	result.numerator = 0;
	result.denominator = 0;
	cout << "\nРазность двух дробей:\n";
	result = first - second;
	result.Output();
	result.numerator = 0;
	result.denominator = 0;
	cout << "\nПроизведение двух дробей:\n";
	result = first * second;
	result.Reduce();
	result.Output();
	result.numerator = 0;
	result.denominator = 0;
	cout << "\nЧастное двух дробей:\n";
	result = first / second;
	result.Reduce();
	result.Output();
	result.numerator = 0;
	result.denominator = 0;
	cout << "\nСокращение первой дроби(если возможно):\n";
	first.Reduce();
	first.Output();
	cout << "\nСокращение второй дроби(если возможно):\n";
	second.Reduce();
	second.Output();
}