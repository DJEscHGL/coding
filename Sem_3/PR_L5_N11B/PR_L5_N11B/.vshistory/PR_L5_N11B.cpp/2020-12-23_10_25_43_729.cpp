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
	struct tm* tm_ptr;
	time_t the_time;
	(void)time(&the_time);
	tm_ptr = gmtime(&the_time);
	printf("Raw time is %ldn", the_time);
	printf("gmtime gives:n");
	printf("date: %02d/%02d/%02dn",
		tm_ptr->tm_year, tm_ptr->tm_mon + 1, tm_ptr->tm_mday);
	printf("time: %02d:%02d:%02dn",
		tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
	exit(0);
}