#include <iostream>
#include <locale>
#include <Windows.h>

using namespace std;

class Complex {
public:
	double a, b; 
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
		out << num.a << num.b << "i" << "; ";
	else
	{
		if (num.b == 0)
			out << num.a << "+" << "i" << "; ";
		else
			out << num.a << "+" << num.b << "i" << "; ";
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
		cout << "{";
		for (int i = 0; i < n; i++) {
			cout << *vector[i];
		}
		cout << "}" << endl;
	}
};

void Mult(ComplexVector v1, ComplexVector v2, int n) {
	cout << "{";
	for (int i = 0; i < n; i++) {
		Complex res;
		res = *v1.vector[i] * *v2.vector[i];
		cout << res;
	}
	cout << "}" << endl;
}

void Summ(ComplexVector v1, ComplexVector v2, int n) {
	cout << "{";
	for (int i = 0; i < n; i++) {
		Complex res;
		res = *v1.vector[i] + *v2.vector[i];
		cout << res;
	}
	cout << "}" << endl;
}

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
		cout << "0.Выход\n1.Вывести все векторы\n2.Сложить вектора\n3.Умножить вектора\n";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			for (int i = 0; i < num; i++) {
				Vectors[i]->Out();
				cout << endl;
			}
			system("pause");
			break;
		case 2:			
			system("cls");
			cout << "Какие вектора сложить от 0 до " << num - 1 << ": ";
			cin >> v1;
			cin >> v2;
			Summ(*Vectors[v1], *Vectors[v2], n);
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Какие вектора умножить от 0 до " << num - 1 << ": ";
			cin >> v1;
			cin >> v2;
			Mult(*Vectors[v1], *Vectors[v2], n);
			system("pause");
			break;
		}
	}
}