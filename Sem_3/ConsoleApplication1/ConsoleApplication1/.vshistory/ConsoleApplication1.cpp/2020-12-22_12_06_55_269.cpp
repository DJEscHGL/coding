#include <stdio.h>
#include <math.h>

#define eps 0.1
double fx(double x) { return x * x - 17; } // вычисляемая функция
double dfx(double x) { return 2 * x; } // производная функции

typedef double(*function)(double x); // задание типа function

double solve(function fx, function dfx, double x0) {
    double x1 = x0 - fx(x0) / dfx(x0); // первое приближение
    while (fabs(x1 - x0) > eps) { // пока не достигнута точность 0.000001
        x0 = x1;
        x1 = x0 - fx(x0) / dfx(x0); // последующие приближения
    }
    return x1;
}

int main() {
    printf("%f\n", solve(fx, dfx, 4)); // вывод на экран
    return 0;
}