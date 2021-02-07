#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t seconds;
	time_t sec;
	time_t min;
	time_t hour;
	void func() {
		seconds = time(NULL);
		cout << "sec = " << seconds << endl;
		cout << (seconds % 86400 - seconds / 86400) % 86400 << ":" << seconds % 3600 / 60 << ":" << seconds % 60 << endl; // время при компиляции и запуске программы
	}
};



int main() {
	setlocale(0, "");
	Time obj;
	obj.func();
}