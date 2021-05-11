#include <iostream>
#include <conio.h>

using namespace std;

class Stringg {
public:
	int size;
	char* str;
	Stringg() {
		cout << "Введите длину строки: ";
		cin >> size;
		str = new char[size];
	}
	Stringg(char* ch) {
		str = ch;
		size = sizeof(str) / sizeof(char);
	}
	Stringg(int nn) {
		size = nn;
		str = new char[size];
	}
	Stringg(const Stringg& obj) {
		size = obj.size;
		str = new char[size];
		for (int i = 0; i < size; i++) {
			str[i] = obj.str[i];
		}
	}
	~Stringg() {
		delete[] str;
	}
	Stringg operator= (Stringg obj) {
		size = obj.size;
		for (int i = 0; i < size; i++) {
			str[i] = obj.str[i];
		}
		return *this;
	}
	Stringg operator+ (Stringg obj) {
		int n = size;
		size += obj.size;
		for (int i = n, j = 0; i < size; i++, j++) {
			str[i] = obj.str[j];
		}
		return *this;
	}
	Stringg operator- (char obj) {
		int k = 0;
		for (int i = 0; i < size; i++) {
			if (str[i] == obj)
				str[i] = ' ';
		}
		for (int i = 0; i < size; i++) {
			if (str[i] == ' ') {
				k++;
				for (int j = i; j < size - 1; j++)
					str[j] = str[j + 1];
			}
		}
		int i = size - 1;
		while (k != 0) {
			str[i] = ' ';
			i--;
			k--;
		}
		return *this;
	}
};

istream& operator>> (istream& in, Stringg* obj) {
	for (int i = 0; i < obj->size; i++)
		in >> obj->str[i];
	return in;
}

ostream& operator<< (ostream& out, Stringg obj) {
	for (int i = 0; i < obj.size; i++) {
		out << obj.str[i];
	}
	return out;
}

int main() {
	setlocale(0, "");
	Stringg* stroka;
	stroka = new Stringg();
	cin >> stroka;
	cout << *stroka << endl;
	Stringg res(stroka->size * 2);
	res = *stroka + (*stroka);
	cout << res;
	*stroka = *stroka - 'w';
	cout << endl << *stroka;
}