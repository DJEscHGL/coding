#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t unix;
	time_t seconds;
	time_t minutes;
	time_t hours;
	void func() {
		unix = time(NULL);
		seconds = unix % 60;
		minutes = unix % 3600 / 60;
		hours = unix % 86400 / 3600 + 3;
		cout << hours << ":" << minutes << ":" << seconds << endl; // время при компиляции и запуске программы
	}
};



int main() {
	setlocale(0, "");
	Time obj;
	obj.func();

}