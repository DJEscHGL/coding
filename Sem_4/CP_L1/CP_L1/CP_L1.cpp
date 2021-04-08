#include <iostream>
#include <new>

using namespace std;

int num, siz; // количество и размернось векторов

class Vector {
public:
	int n;
	double* points;
	// Конструктор без параметров
	Vector() {
		n = siz;
		points = new double[n];
	}
	// Конструктор для результата операций
	Vector(int nn) {
		n = nn;
		points = new double[n];
	}
	// Конструктор с параметром типа double*
	Vector(double* arr, int nn) {
		n = nn;
		points = new double[n];
		for (int i = 0; i < n; i++) {
			points[i] = arr[i];
		}
	}
	// Конструктор копирования
	Vector(const Vector& vect) {
		n = vect.n;
		points = new double[n];
		for (int i = 0; i < n; i++) {
			points[i] = vect.points[i];
		}
	}
	// Деструктор
	~Vector() {
		delete[] points;
	}
	// Метод для нахождения модуля вектора
	double Module() {
		double temp = 0;
		for (int i = 0; i < n; i++) {
			temp += (points[i] * points[i]);
		}
		return sqrt(temp);
	}
	// Метод скалярного произведения векторов
	void ScalarMult(Vector v1, Vector v2) {
		double temp = 0;
		for (int i = 0; i < v1.n; i++) {
			temp += (v1.points[i] * v2.points[i]);
		}
		cout << "Ответ: " << temp << endl;
	}
	// Метод векторного произведения векторов
	void VectorMult(Vector v1, Vector v2) {
		double x, y, z;
		if (n != 3) {
			cout << "Размерность вектора должа быть равна 3\n";
			return;
		}
		else {
			x = v1.points[1] * v2.points[2] - v1.points[2] * v2.points[1];
			y = v1.points[2] * v2.points[0] - v1.points[0] * v2.points[2];
			z = v1.points[0] * v2.points[1] - v1.points[1] * v2.points[0];
			cout << "Ответ: { " << x << "; " << y << "; " << z << " }\n";
		}
	}
	// Перегрузка операции присвоения
	Vector operator= (Vector obj) {
		n = obj.n;
		for (int i = 0; i < n; i++) {
			points[i] = obj.points[i];
		}
		return *this;
	}
	// Перегрузка операции сложения
	Vector operator+ (Vector obj) {
		for (int i = 0; i < n; i++) {
			points[i] += obj.points[i];
		}
		return *this;
	}
	// Перегрузка операции вычитания
	Vector operator- (Vector obj) {
		for (int i = 0; i < n; i++) {
			points[i] -= obj.points[i];
		}
		return *this;
	}
	// Перегрузка операции постфиксного инкремента
	Vector& operator++() {
		for (int i = 0; i < n; i++) {
			points[i]++;
		}
		return *this;
	}
	// Перегрузка операции постфиксного декремента
	Vector& operator--() {
		for (int i = 0; i < n; i++) {
			points[i]--;
		}
		return *this;
	}
	// Перегрузка операции префиксного инкремента
	Vector operator++ (int) {
		Vector obj(*this);
		++(*this);
		return obj;
	}
	// Перегрузка операции префиксного декремента
	Vector operator-- (int) {
		Vector obj(*this);
		--(*this);
		return obj;
	}
	// Перегрузка операции умножения на скаляр
	Vector operator* (double a) {
		for (int i = 0; i < n; i++) {
			points[i] *= a;
		}
		return *this;
	}
};
// Перегрузка операции ввода
istream& operator>> (istream& in, Vector* vect) {
	for (int i = 0; i < num; i++) {
		cout << "Введите вектор: ";
		for (int j = 0; j < siz; j++) {
			cin >> vect[i].points[j];
		}
	}
	return in;
}
// Перегрузка операции вывода
ostream& operator<< (ostream& out, Vector vect) {
	out << "s{ ";
	for (int j = 0; j < siz; j++) {
		out << vect.points[j] << "; ";
	}
	out << "}\n";
	return out;
}
// Функция тестирования функционала
void Test(Vector* vectors) {
	cin >> vectors;
	Vector result(siz); // Вектор результата операций
	int f_st, s_nd; // Номера для 2 векторов
	double scalar_num;  // Скаляр для умножения
	bool flag = true; // Зацикливание меню
	int choice, sub_choice; // Переменные для меню и подменю
	while (flag) {
		system("cls");
		cout << "0.Выход\n1.Вывод векторов\n2.Сложение векторов\n3.Вычитание векторов\n4.Инкремент\n5.Декремент\n6.Умножение вектора на скаляр";
		cout << "\n7.Модуль вектора\n8.Скалярное произведение векторов\n9.Векторное произведение векторов\n";
		cin >> choice;
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			system("cls");
			for (int i = 0; i < num; i++) {
				cout << "vector[" << i << "] ";
				cout << vectors[i];
			}
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Какие вектора сложить (от 0 до " << num - 1 << ")?\n";
			cin >> f_st >> s_nd;
			result = vectors[f_st] + vectors[s_nd];
			cout << "Ответ: " << result;
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Какие вектора вычесть (от 0 до " << num - 1 << ")?\n";
			cin >> f_st >> s_nd;
			result = vectors[f_st] - vectors[s_nd];
			cout << "Ответ: " << result;
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "Какой вектор инкреминировать (от 0 до " << num - 1 << ")?\n";
			cin >> f_st;
			cout << "1.Постфиксное(vector++)\n2.Префиксное(++vector)\n";
			cin >> sub_choice;
			switch (sub_choice) {
			case 1:
				vectors[f_st]++;
				break;
			case 2:
				++vectors[f_st];
			}
			cout << "Ответ: " << vectors[f_st];
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "Какой вектор декреминировать (от 0 до " << num - 1 << ")?\n";
			cin >> f_st;
			cout << "1.Постфиксное(vector--)\n2.Префиксное(--vector)\n";
			cin >> sub_choice;
			switch (sub_choice) {
			case 1:
				vectors[f_st]--;
				break;
			case 2:
				--vectors[f_st];
			}
			cout << "Ответ: " << vectors[f_st];
			system("pause");
			break;
		case 6:
			system("cls");
			cout << "Какой вектор умножить (от 0 до " << num - 1 << ")?\n";
			cin >> f_st;
			cout << "Введите число на которое нужно умножить: ";
			cin >> scalar_num;
			result = vectors[f_st] * scalar_num;
			cout << "Ответ: " << result;
			system("pause");
			break;
		case 7:
			system("cls");
			cout << "Модуль какого вектора найти (от 0 до " << num - 1 << ")?\n";
			cin >> f_st;
			cout << "Ответ: " << vectors[f_st].Module() << endl;
			system("pause");
			break;
		case 8:
			system("cls");
			cout << "Какие вектора скалярно перемножить (от 0 до " << num - 1 << ")?\n";
			cin >> f_st >> s_nd;
			vectors[0].ScalarMult(vectors[f_st], vectors[s_nd]);
			system("pause");
			break;
		case 9:
			system("cls");
			cout << "Какие вектора векторно перемножить (от 0 до " << num - 1 << ")?\n";
			cin >> f_st >> s_nd;
			vectors[0].VectorMult(vectors[f_st], vectors[s_nd]);
			system("pause");
			break;
		}
	}
}

int main() {
	setlocale(0, ""); //Русская локализация
	Vector* vectors; // Указатель на массив векторов
	cout << "Введите количество векторов: ";
	cin >> num;
	cout << "Введите размерность векторов: ";
	cin >> siz;
	vectors = new Vector[num]; // Инициализация массива векторов
	Test(vectors); //Вызов тестовой функции
	// Вызываем деструктор
	for (int i = 0; i < num; i++) {
		vectors[i].~Vector();
	}
}