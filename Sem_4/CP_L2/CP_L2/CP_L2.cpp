#include <iostream>

using namespace std;

class Gauss {
public:
	int n;
	double** coefficients;
    double* y;

    Gauss(int nn) {
        // Заполняем все коэффициенты и y
        n = nn;
		coefficients = new double* [n];
		for (int i = 0; i < n; i++) {
			coefficients[i] = new double[n];
		}
        y = new double[n];
        for (int i = 0; i < n; i++) {
            cout << "Введите коэффициенты перед X для "<< i + 1 << " уравнения:\n";
            for (int j = 0; j < n; j++) {
                cin >> coefficients[i][j];
            }
            cout << "Введите Y для " << i + 1 << " уравнения:\n";
            cin >> y[i];
        }
	}
	~Gauss() {

	}
    // Функция вывода системы уравнений
    void Output() {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << coefficients[i][j] << "*x" << j;
                if (j < n - 1)
                    cout << " + ";
            }
            cout << " = " << y[i] << endl;
        }
    }
    // Функция вычисления методом Гаусса
	double* Calculate() {
        double* x, max;
        int k, index;
        const double eps = 0.00001;  // Точность
        x = new double[n];
        k = 0;
        while (k < n)
        {
            // Поиск строки с максимальным coefficients[i][k]
            max = abs(coefficients[k][k]);
            index = k;
            for (int i = k + 1; i < n; i++)
            {
                if (abs(coefficients[i][k]) > max)
                {
                    max = abs(coefficients[i][k]);
                    index = i;
                }
            }
            // Перестановка строк
            if (max < eps)
            {
                // Нет ненулевых диагональных элементов
                cout << "Решение получить невозможно из-за нулевого столбца " << index << endl;
                return 0;
            }
            for (int j = 0; j < n; j++)
            {
                double temp = coefficients[k][j];
                coefficients[k][j] = coefficients[index][j];
                coefficients[index][j] = temp;
            }
            double temp = y[k];
            y[k] = y[index];
            y[index] = temp;
            // Нормализация уравнений
            for (int i = k; i < n; i++)
            {
                double temp = coefficients[i][k];
                if (abs(temp) < eps) 
                    continue; // Для нулевого коэффициента пропустить
                for (int j = 0; j < n; j++) {
                    coefficients[i][j] = coefficients[i][j] / temp;
                }
                y[i] = y[i] / temp;
                if (i == k)
                    continue; // Уравнение не вычитать само из себя
                for (int j = 0; j < n; j++) {
                    coefficients[i][j] = coefficients[i][j] - coefficients[k][j];
                }
                y[i] = y[i] - y[k];
            }
            k++;
        }
        // Обратная подстановка
        for (k = n - 1; k >= 0; k--)
        {
            x[k] = y[k];
            for (int i = 0; i < k; i++)
                y[i] = y[i] - coefficients[i][k] * x[k];
        }
        return x;
	}
};

int main() {
    setlocale(0, "");
    int n;
    double* x;
    cout << "Введите количество уравнений: ";
    cin >> n;
    Gauss sys(n);
    sys.Output();
    cout << endl;
    x = sys.Calculate();
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "]=" << x[i] << endl;
}