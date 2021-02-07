#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:
	time_t seconds;
	void func() {
		seconds = time(NULL);
		cout << seconds / 3600 << endl;
	}
};



int main() {
	/*Time obj;
	obj.func();*/
    time_t now = time(0);
    cout << "Number of sec since January 1,1970:" << now << endl;
    tm* ltm = localtime(&now);
    cout << "Year" << 1970 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;
    cout << "Time: " << 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
}