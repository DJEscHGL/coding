#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;
ifstream input("input.txt");
ofstream output("output.txt");

class Bus
{
private:
	string name;
	string num;
	int route;
	string brand;
	int year;
	double run;
public:
	string GetName()
	{	
		return name;
	}
	string GetNum()
	{
		return num;
	}
	int GetRoute()
	{
		return route;
	}
	string GetBrand()
	{
		return brand;
	}

	int GetYear()
	{
		return year;
	}
	double GetRun()
	{
		return run;
	}
	void SetName(string valName)
	{
		name = valName;
	}
	void SetNum(string valNum)
	{
		num = valNum;
	}
	void SetRoute(int valRoute)
	{
		route = valRoute;
	}
	void SetBrand(string valBrand)
	{
		brand = valBrand;
	}
	void SetYear(int valYear)
	{
		year = valYear;
	}
	void SetRun(double valRun)
	{
		run = valRun;
	}
	void Show()
	{
		output << name << "\t" << num << "\t" << route << "\t" << brand << "\t" << year << "\t" << run << endl;
	}
};

void ch1(Bus* bass, int n)
{
	int RouteNum;
	system("cls");
	cout << "Введите номер маршрута: ";
	cin >> RouteNum;
	system("cls");
	output << "name \t num \t route \t brand \t year \t run" << endl;
	for (int i = 0; i < n; i++)
	{
		if (bass[i].GetRoute() == RouteNum)
			bass[i].Show();
	}
}

void ch2(Bus* bass, int n)
{
	system("cls");
	output << "name \t\t num \t route \t brand \t year \t run" << endl;
	for (int i = 0; i < n; i++)
	{
		if (bass[i].GetYear() < 2010)
			bass[i].Show();
	}
}

void ch3(Bus* bass, int n)
{
	system("cls");
	output << "name \t\t num \t route \t brand \t year \t run" << endl;
	for (int i = 0; i < n; i++) {
		if (bass[i].GetRun() > 10000)
			bass[i].Show();
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	string b, k, q;
	double d;
	int f;
	//cout << "Количество Автобусов: ";
	input >> n;
	Bus* bass = new Bus[n];
	for (int i = 0; i < n; i++)
	{
		//cout << "Имя Водителя: ";
		input.get();
		getline(input, b);
		bass[i].SetName(b);
		//cout << "Пробег Автобуса: ";
		input >> d;
		bass[i].SetRun(d);
		//cout << "Номер Автобуса: ";
		input.get();
		getline(input, q);
		bass[i].SetNum(q);
		//cout << "Номер Маршрута: ";
		input >> f;
		bass[i].SetRoute(f);
		//cout << "Марка Автобуса: ";
		input.get();
		getline(input, k);
		bass[i].SetBrand(k);
		//cout << "Год Начала Эксплуатации: ";
		input >> f;
		bass[i].SetYear(f);
	}
	system("cls");
	bool flag = true;
	while (flag)
	{
		int choice;
		cout << "Введите номер нужного пункта\n1.Cписок автобусов для заданного номера маршрута.\n2.Cписок автобусов, которые эксплуатируются больше 10 лет.\n3.Cписок автобусов, пробег у которых больше 10 000 км.\n\nДля выхода из меню выбора нажмите 0" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			ch1(bass, n);
			break;
		case 2:
			ch2(bass, n);
			break;
		case 3:
			ch3(bass, n);
			break;
		default:
			system("cls");
			cout << "Введёт неверный вариант, программа завершена";
			break;
		}
	}
	input.close();
	output.close();
}