#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t unix;
	time_t second;
	time_t minutes;
	time_t hours;
	void SetCurrentTime() {
		unix = time(NULL);
		cout << unix << end;
		second = unix % 60;
		minutes = unix % 3600 / 60;
		hours = unix % 86400 / 3600 + 3;
	}
};

class DayType : public Time{
public:
	void output() {
		cout << unix << endl;
		if(second < 10)
			cout << hours << ":" << minutes << ":0" << second; // время при компиляции и запуске программы
		else
			cout << hours << ":" << minutes << ":" << second; // время при компиляции и запуске программы

	}
};


int main() {
	setlocale(0, "");
	DayType obj;
	obj.output();
}