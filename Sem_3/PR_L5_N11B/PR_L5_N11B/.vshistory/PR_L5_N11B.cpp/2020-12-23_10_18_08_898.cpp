#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t seconds;
	void func() {
		seconds = time(NULL);
		cout << "Дней с 1970 года 1 января === " << seconds / 86400;
	}
};



int main() {
	setlocale(0, "");
	Time obj;
	obj.func();
}