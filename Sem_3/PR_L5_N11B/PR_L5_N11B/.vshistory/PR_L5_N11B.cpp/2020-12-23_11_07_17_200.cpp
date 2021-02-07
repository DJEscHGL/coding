#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t seconds;
	void func() {
		seconds = time(NULL);
		cout << seconds % 60 << endl;
		cout << seconds % 3600 / 60 << endl; // минуты
		cout << seconds % 60 << endl; // секунды
	}
};



int main() {
	setlocale(0, "");
	Time obj;
	obj.func();
}