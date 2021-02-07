#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t seconds;
	void func() {
		seconds = time(NULL);
		cout << seconds / 3600;
	}
};



int main() {
	Time obj;
	obj.func();
}