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
	void Summ(ComplexVector v1, ComplexVector v2) {
		for (int i = 0; i < n; i++) {
			ComplexVector res(n);
			res = *v1.vector[i] + *v2.vector[i];
		}
	}
	void Out() {
		for (int i = 0; i < n; i++) {
			cout << *vector[i];
		}
	}
	ComplexVector operator= (ComplexVector obj) {
		for (int i = 0; i < n; i++) {
			vector[i] = new Complex;
			vector[i] = obj.vector[i];
		}
		return *this;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num, n;
	cout << "Введите количество векторов: ";
	cin >> num;
	cout << "Введите размерность векторов: ";
	cin >> n;
	auto Vectors = new ComplexVector*[num];
	for (int i = 0; i < num; i++) {
		Vectors[i] = new ComplexVector(n);
	}
	int v1, v2;

	bool flag = true;
	while (flag) {
		system("cls");
		int choice;
		cout << "0.Выход\n1.Сложить вектора\n2.Умножить вектора\n";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:			
			system("cls");
			cout << "Какие вектора сложить от 0 до " << num << ": ";
			cin >> v1;
			cin >> v2;
			
			system("pause");
			break;
		}
	}
}