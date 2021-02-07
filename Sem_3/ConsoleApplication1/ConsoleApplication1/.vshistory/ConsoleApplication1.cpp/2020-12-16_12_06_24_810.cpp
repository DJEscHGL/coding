#include <Windows.h>
#include <time.h>
#include <iostream>

using namespace std;

class Tree {
public:
	double number, age, plod;
	//string name, color;
	//virtual void setName() = 0;
	//virtual void setColor() = 0;
	virtual void setAge() = 0;
	//virtual void setNumber() = 0;
	virtual void setPlod() = 0;
	virtual void Show() = 0;
	virtual void setParameter() = 0;
	double getNumbert() {
		return number;
	}
	double getAge() {
		return age;
	}
	double getPlod() {
		return plod;
	}
};

class Apple : public Tree {
public:
	string breed;

	void setParameter() {
		cout << "Введите сорт яблони: ";
		cin >> breed;
	}
	virtual void setPlod() {
		cout << "Плодоношение: ";
		cin >> plod;
	}
	virtual void setAge() {
		cout << "Введите возраст яблони:";
		cin >> age;
	}

	virtual void Show() {
		cout << breed << " \t " << age << " \t\t " << plod << endl;
	}
};

class Cherry : public Tree {
	string species;
	void setParameter() {
		cout << "Введите сорт вишни: ";
		cin >> species;
	}
	virtual void setPlod() {
		cout << "Плодоношение: ";
		cin >> plod;
	}
	virtual void setAge() {
		cout << "Введите возраст вишни:";
		cin >> age;
	}

	virtual void Show() {
		cout << species << " \t " << age << " \t\t " << plod << endl;
	}

};

class Pear : public Tree {
	string race;
	void setParameter() {
		cout << "Введите сорт груши: ";
		cin >> race;
	}
	virtual void setPlod() {
		cout << "Плодоношение: ";
		cin >> plod;
	}
	virtual void setAge() {
		cout << "Введите возраст груши:";
		cin >> age;
	}

	virtual void Show() {
		cout << race << " \t " << age << " \t\t " << plod << endl;
	}
};

class Plum : public Tree {
	string poison;
	void setParameter() {
		cout << "Введите сорт сливы: ";
		cin >> poison;
	}
	virtual void setPlod() {
		cout << "Плодоношение: ";
		cin >> plod;
	}
	virtual void setAge() {
		cout << "Введите возраст сливы:";
		cin >> age;
	}

	virtual void Show() {
		cout << poison << " \t " << age << " \t\t " << plod << endl;
	}
};

class Peach : public Tree {
	string poi;
	void setParameter() {
		cout << "Введите сорт персика: ";
		cin >> poi;
	}
	virtual void setPlod() {
		cout << "Плодоношение: ";
		cin >> plod;
	}
	virtual void setAge() {
		cout << "Введите возраст персика:";
		cin >> age;
	}

	virtual void Show() {
		cout << poi << " \t " << age << " \t\t " << plod << endl;
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(NULL));
	int NumberOfApple, NumberOfCherry, NumberOfPear, NumberOfPlum, NumberOfPeach, num;
	cout << "Количество яблонь = ";
	cin >> NumberOfApple;
	cout << "Количество вишень = ";
	cin >> NumberOfCherry;
	cout << "Количество груш = ";
	cin >> NumberOfPear;
	cout << "Количество слив = ";
	cin >> NumberOfPlum;
	cout << "Количество персиков = ";
	cin >> NumberOfPeach;
	num = NumberOfApple + NumberOfCherry + NumberOfPear + NumberOfPlum + NumberOfPeach;
	Tree** trees = new Tree * [num];
	for (int i = 0; i < NumberOfApple; i++)
	{
		trees[i] = new Apple;
		//trees[i]->setName();
		trees[i]->setAge();
		trees[i]->setPlod();
		trees[i]->setParameter();
	}
	for (int i = NumberOfApple; i < NumberOfApple + NumberOfCherry; i++)
	{
		trees[i] = new Cherry;
		//pets[i]->setName();
		trees[i]->setAge();
		trees[i]->setPlod();;
		trees[i]->setParameter();
	}
	for (int i = NumberOfApple + NumberOfCherry; i < NumberOfApple + NumberOfCherry + NumberOfPear; i++)
	{
		trees[i] = new Pear;
		//pets[i]->setName();
		trees[i]->setAge();
		trees[i]->setPlod();;
		trees[i]->setParameter();
	}
	for (int i = NumberOfApple + NumberOfCherry + NumberOfPear; i < NumberOfApple + NumberOfCherry + NumberOfPear + NumberOfPlum; i++)
	{
		trees[i] = new Plum;
		//pets[i]->setName();
		trees[i]->setAge();
		trees[i]->setPlod();;
		trees[i]->setParameter();
	}
	for (int i = NumberOfApple + NumberOfCherry + NumberOfPear + NumberOfPlum; i < NumberOfApple + NumberOfCherry + NumberOfPear + NumberOfPlum + NumberOfPeach; i++)
	{
		trees[i] = new Peach;
		//pets[i]->setName();
		trees[i]->setAge();
		trees[i]->setPlod();;
		trees[i]->setParameter();
	}
	cout << "====================== Яблони ======================" << endl;
	for (int i = 0; i < NumberOfApple; i++)
	{

		cout << "Сорт \t Плодоношение \t Возраст" << endl;
		trees[i]->Show();
	}

	cout << "====================== Вишни ========================" << endl;
	for (int i = NumberOfApple; i < NumberOfApple + NumberOfCherry; i++)
	{

		cout << "Сорт \t Плодоношение \t Возраст" << endl;
		trees[i]->Show();
	}

	cout << "====================== Груши ======================" << endl;
	for (int i = NumberOfApple + NumberOfCherry; i < NumberOfApple + NumberOfCherry + NumberOfPear; i++)
	{

		cout << "Сорт \t Плодоношение \t Возраст" << endl;
		trees[i]->Show();
	}

	cout << "======================= Сливы ========================" << endl;
	for (int i = NumberOfApple + NumberOfCherry + NumberOfPear; i < NumberOfApple + NumberOfCherry + NumberOfPear + NumberOfPlum; i++)
	{

		cout << "Сорт \t Плодоношение \t Возраст" << endl;
		trees[i]->Show();
	}

	cout << "===================== Персики ======================" << endl;
	for (int i = num - NumberOfPeach; i < num; i++)
	{
		cout << "Сорт \t Плодоношение \t Возраст" << endl;
		trees[i]->Show();
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
