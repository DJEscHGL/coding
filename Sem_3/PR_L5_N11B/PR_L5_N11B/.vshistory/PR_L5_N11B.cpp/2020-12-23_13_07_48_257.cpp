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
		else {
			if (minutes < 10) {
				if (seconds < 10) {
					cout <<  hours << ":0" << minutes << ":0" << seconds;
				}
				else
					cout << hours << ":0" << minutes << ":" << seconds;
			}
			else {
				if (seconds < 10) {
					cout << hours << ":" << minutes << ":0" << seconds;
				}
				else
					if (seconds < 10) {
						cout << hours << ":" << minutes << ":" << seconds;
					}
			}
		}
		if (hours <= 6)
			cout << " ночи";
		else if (hours <= 12)
			cout << " утра";
		else if (hours <= 18)
			cout << " дня";
		else if (hours <= 23)
			cout << " вечера";
	}
};


int main() {
	setlocale(0, "");
	DayType obj;
	obj.SetCurrentTime();
	obj.output();
}