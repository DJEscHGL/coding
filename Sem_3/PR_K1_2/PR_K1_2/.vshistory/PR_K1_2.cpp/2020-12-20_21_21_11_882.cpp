#include <iostream>
#include <locale>
#include <Windows.h>

using namespace std;

class Man {
public:
	string name, gender;
	int age;
	double weight;
	Man(string newgender) {
		gender = newgender;
	}
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
	Student(int num) {
		year = num;
	}
	Student operator++(int){
		year++;
		return *this;
	}
	Student operator--(int) {
		year++;
		return *this;
	}
	void SetYear(int newyear) {
		year = newyear;
	}
	void InDecYear(Student person) {
		int ch;
		cout << "1. Увеличить на 1\n2. Уменьшить на 1";
		cin >> ch;
		if (ch == 1)
			person++;
		else
			person--;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name, gender;
	int age, year;
	double weight;
	Student fst(year);
	fst.SetAge(age);
	fst.SetName(name);
	fst.SetWeight(weight);
}