#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t unix;
	time_t seconds;
	time_t minutes;
	time_t hours;
	void SetCurrentTime() {
		unix = time(NULL);
		seconds = unix % 60;
		minutes = unix % 3600 / 60;
		hours = unix % 86400 / 3600 + 3;
	}
};

class DayType : public Time{
public:
	void output() {
		cout << unix << " ";
		if(seconds < 10)
			cout << hours << ":" << minutes << ":0" << seconds; // время при компиляции и запуске программы
		else
			cout << hours << ":" << minutes << ":" << seconds; // время при компиляции и запуске программы

	}
};


int main() {
	setlocale(0, "");
	DayType obj;
	obj.output();
}