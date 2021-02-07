#include <iostream>
#include <ctime>
#pragma warning(suppress : 4996)

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
		cout << seconds % 86400 / 24  << ":" << seconds % 3600 / 60 << ":" << seconds % 60 << endl; // время при компиляции и запуске программы
	}
};



int main() {
	setlocale(0, "");
	Time obj;
	obj.func();
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	cout << "The local date and time is: " << dt << endl;

	// convert now to tm struct for UTC
	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "The UTC date and time is:" << dt << endl;
}