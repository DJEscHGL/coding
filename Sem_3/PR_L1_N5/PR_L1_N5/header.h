#include <iostream>

using namespace std;

class Worker {
private:
	string name;
	string position;
	int year;
	double salary;
public:
	string GetName();
	string GetPosition();
	int GetYear();
	double GetSalary();
	void SetName(string valName);
	void SetPosition(string valPosition);
	void SetYear(int valYear);
	void SetSalary(double valSalary);
	void Show();
};