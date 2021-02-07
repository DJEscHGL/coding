#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t seconds;
	void func() {
		seconds = time(NULL);
		cout << "Год " << seconds / 86400 << endl;
		cout << seconds;
	}
};



int main() {
	setlocale(0, "");
	Time obj;
	obj.func();
}