#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <locale>

using namespace std;
ifstream input("input.txt");
ofstream output("output.txt");

class File {
private:
	string name;
	double size;
	string date;
	int calls;
public:
	string GetName() {
		return name;
	}
	double GetSize() {
		return size;
	}
	string GetDate() {
		return date;
	}
	int GetCalls() {
		return calls;
	}
	void SetName(string valName) {
		name = valName;
	}
	void SetSize(double valSize) {
		size = valSize;
	}
	void SetDate(string valDate) {
		date = valDate;
	}
	void SetCalls(int valCalls) {
		calls = valCalls;
	}
	void Show() {
		cout << name << "\t" << size << "\t" << date << "\t" << calls << endl;
		output << name << "\t" << size << "\t" << date << "\t" << calls << endl;
	}
};

void ch1(File* files1, int n) {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (files1[i].GetName()[0] >= files1[j].GetName()[0])
			{
				swap(files1[i], files1[j]);
			}
		}
	}
	cout << "Имя\tРазмер\tДата\t\tВызовов" << endl;
	output << "Имя\tРазмер\tДата\t\tВызовов" << endl;
	for (int i = 0; i < n; i++) {
		files1[i].Show();
	}
	output << endl;
}

void ch2(File* files1, int n) {
	double bigsize;
	system("cls");
	cout << "Введите размер файлов = ";
	cin >> bigsize;
	system("cls");
	cout << "Имя\tРазмер\tДата\t\tВызовов" << endl;
	output << "Имя\tРазмер\tДата\t\tВызовов" << endl;
	for (int i = 0; i < n; i++) {
		if (files1[i].GetSize() > bigsize)
			files1[i].Show();
	}
	cout << endl;
	output << endl;
}

void ch3(File* files1, int n) {
	double bigcalls;
	system("cls");
	cout << "Введите количество вызовов = ";
	cin >> bigcalls;
	system("cls");
	cout << "Имя\tРазмер\tДата\t\tВызовов" << endl;
	output << "Имя\tРазмер\tДата\t\tВызовов" << endl;
	for (int i = 0; i < n; i++) {
		if (files1[i].GetCalls() > bigcalls)
			files1[i].Show();
	}
	cout << endl;
	output << endl;
}

int main() {
	SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	SetConsoleOutputCP(866);
	//output.imbue(locale("ru_RU"));
	setlocale(LC_ALL, "ru");
	int n;
	string s, q;
	double d;
	int in;
	if (input.is_open())
	{
		cout << "Файл input.txt открытый" << endl;
	}
	else
		input.open("input.txt");
	if (output.is_open())
	{
		cout << "Файл output.txt открытый" << endl;
	}
	else
		output.open("output.txt");
	//cout << "Количество файлов = ";
	input >> n;
	File* files = new File[n];
	for (int i = 0; i < n; i++) {
		//cout << "Имя = ";
		input.get();
		getline(input, s);
		files[i].SetName(s);
		//cout << "Размер = ";
		input >> d;
		files[i].SetSize(d);
		//cout << "Дата = ";
		input.get();
		getline(input, q);
		files[i].SetDate(q);
		//cout << "Вызовы = ";
		input >> in;
		files[i].SetCalls(in);
	}
	bool flag = true;
	while (flag) {
		int choice;
		cout << "Введите номер нужного пункта\n0.Выход\n1.Список файлов в алфавитном порядке.\n2.Список файлов превышающий введённый размер.\n3.Список файлов превышающий введённое число запросов." << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			ch1(files, n);
			system("pause");
			system("cls");
			break;
		case 2:
			ch2(files, n);
			system("pause");
			system("cls");
			break;
		case 3:
			ch3(files, n);
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			cout << "Введён неверный вариант";
			break;
		}
	}
	input.close();
	output.close();
}