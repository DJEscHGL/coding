#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t seconds;
	void func() {
		seconds = time(NULL);
		cout << seconds / 3600 << endl;
		cout << seconds / 60 << endl;
	}
};



int main() {
	Time obj;
	obj.func();
}