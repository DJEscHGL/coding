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
		if (hours < 10) {
			if (minutes < 10) {
				if (seconds < 10) {
					cout << "0" << hours << ":0" << minutes << ":0" << seconds;
				}
				else
					cout << "0" << hours << ":0" << minutes << ":" << seconds;
			}
			else
				cout << "0" << hours << ":" << minutes << ":" << seconds;
		}
		else
			cout << hours << ":" << minutes << ":" << seconds;
	}
};


int main() {
	setlocale(0, "");
	DayType obj;
	obj.SetCurrentTime();
	obj.output();
}