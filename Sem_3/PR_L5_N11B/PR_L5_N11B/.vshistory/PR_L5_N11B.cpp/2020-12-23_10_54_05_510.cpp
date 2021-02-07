#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t seconds;
	void func() {
		seconds = time(NULL);
		cout << seconds / (3600 * 24) % 365 << endl;
		cout << seconds % 3600 / 60 << endl; // минуты
	}
};



int main() {
	setlocale(0, "");
	Time obj;
	obj.func();
}