#include <iostream>
#include <locale>
#include <Windows.h>

using namespace std;

class Man {
	string name, gender;
	int age;
	double weight;
	void SetName(string newname) {
		name = newname;
	}
	void SetAge(int newage) {
		age = newage;
	}
	void SetWeight(double newweight) {
		weight = newweight;
	}
};

class Student : public Man {
public:
	int year;
	void SetYear(int newyear) {
		year = newyear;
	}

};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}