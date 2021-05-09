// Лаба 5, вариант 13 (в, д)
#include <iostream>
#include <cmath>
using namespace std;

double firstIntegratingFunction(double);
double secondIntegratingFunction(double);
double thirdIntegratingFunction(double);
void simpson(double(*f)(double), double, double, double, double&, int&);
void methodOfMiddleRectangles(double(*f)(double), double, double, double, double&, int&);
void middleRectanglesOutput(double, double&, int&);
void simpsonOutput(double, double&, int&);


int main() {
    setlocale(LC_ALL, "rus");
    int numberOfSpindelsOfSegment = 1;
    double eps, sum = 0;
    cout << "Введите точность: ";
    cin >> eps;
    middleRectanglesOutput( eps, sum, numberOfSpindelsOfSegment);
    cout << endl;
    simpsonOutput(eps, sum, numberOfSpindelsOfSegment);
    system("pause");
    return 0;
}


double firstIntegratingFunction(double x) {
    return x * atan(x);
}
double secondIntegratingFunction(double x) {
    return 1 / ((x + 1) * sqrt(x * x + 1));
}
double thirdIntegratingFunction(double x) {
    return x * sqrt(x + 1);
}


void simpson(double(*f)(double), 
    double lowerIntegratingLimit, double upperIntegratingLimit,
    double eps, double& sum, int& numberOfSpindelsOfSegment) {
    sum = 0;
    numberOfSpindelsOfSegment = 2;
    double sum1 = 0, sum2 = 0, firstApproximation, secondApproximation;
    double h = (upperIntegratingLimit - lowerIntegratingLimit) / (2.0 * numberOfSpindelsOfSegment);
    secondApproximation = (f(lowerIntegratingLimit) + f(upperIntegratingLimit)) / 2;
    for (double x = lowerIntegratingLimit + h; x <= upperIntegratingLimit - h; x += h)
        secondApproximation += f(x);
    secondApproximation *= h;
    do {
        firstApproximation = secondApproximation;
        numberOfSpindelsOfSegment *= 2;
        h = (upperIntegratingLimit - lowerIntegratingLimit) / numberOfSpindelsOfSegment;
        secondApproximation = f(lowerIntegratingLimit) + f(upperIntegratingLimit);
        for (double x = lowerIntegratingLimit + h; x <= upperIntegratingLimit - h; x += 2 * h) 
            secondApproximation += 2 * f(x);
        secondApproximation *= h / 3;
    } while (abs(firstApproximation - secondApproximation) > eps);
    sum1 = secondApproximation;
    do {
        firstApproximation = secondApproximation;
        numberOfSpindelsOfSegment *= 2;
        h = (upperIntegratingLimit - lowerIntegratingLimit) / numberOfSpindelsOfSegment;
        secondApproximation = 0;
        for (double x = lowerIntegratingLimit + 2 * h; x <= upperIntegratingLimit - h; x += 2 * h) 
            secondApproximation += 4 * f(x);
        secondApproximation *= h / 3;
    } while (abs(firstApproximation - secondApproximation) > eps);
    sum2 = secondApproximation;
    sum = sum1 + sum2;
    numberOfSpindelsOfSegment = sqrt(numberOfSpindelsOfSegment);
}

void methodOfMiddleRectangles(double(*f)(double), 
    double lowerIntegratingLimit, double upperIntegratingLimit,
    double eps, double& sum, int& numberOfSpindelsOfSegment) {
    sum = 0;
    double firstApproximation, secondApproximation;
    numberOfSpindelsOfSegment = 4;
    double h = (upperIntegratingLimit - lowerIntegratingLimit) / numberOfSpindelsOfSegment;
    secondApproximation = (f(lowerIntegratingLimit) + f(upperIntegratingLimit)) / 2;

    for (double x = lowerIntegratingLimit + h; x <= upperIntegratingLimit - h; x += h)
        secondApproximation += f(x);
    secondApproximation *= h;
    do {
        firstApproximation = secondApproximation;
        numberOfSpindelsOfSegment *= 2;
        h = (upperIntegratingLimit - lowerIntegratingLimit) / numberOfSpindelsOfSegment;
        secondApproximation = (f(lowerIntegratingLimit) + f(upperIntegratingLimit)) / 2;
        for (double x = lowerIntegratingLimit + h; x <= upperIntegratingLimit - h; x += h)
            secondApproximation += f(x);
        secondApproximation *= h;
    } while (abs(firstApproximation - secondApproximation) > eps);
    sum = secondApproximation;
}


void middleRectanglesOutput(double eps, double& sum, int& numberOfSpindelsOfSegment) {
    methodOfMiddleRectangles(firstIntegratingFunction, 0, 1.7, eps, sum, numberOfSpindelsOfSegment);
    cout << "Значение первого интеграла, вычесленное по формуле средних прямоугольников: "
        << sum << ", число точек деления отрезка = " << numberOfSpindelsOfSegment << endl;
    methodOfMiddleRectangles(secondIntegratingFunction, 0, 0.6, eps, sum, numberOfSpindelsOfSegment);
    cout << "Значение второго интеграла, вычесленное по средних прямоугольников: "
        << sum << ", число точек деления отрезка = " << numberOfSpindelsOfSegment << endl;
    methodOfMiddleRectangles(thirdIntegratingFunction, 2, 7, eps, sum, numberOfSpindelsOfSegment);
    cout << "Значение третьего интеграла, вычесленное средних прямоугольников: "
        << sum << ", число точек деления отрезка = " << numberOfSpindelsOfSegment << endl;
}


void simpsonOutput(double eps, double& sum, int& numberOfSpindelsOfSegment) {
    simpson(firstIntegratingFunction, 0, 1.7, eps, sum, numberOfSpindelsOfSegment);
    cout << "Значение первого интеграла, вычесленное по формуле Симпсона: "
        << sum << ", число точек деления отрезка = " << numberOfSpindelsOfSegment << endl;
    simpson(secondIntegratingFunction, 0, 0.6, eps, sum, numberOfSpindelsOfSegment);
    cout << "Значение второго интеграла, вычесленное по формуле Симпсона: "
        << sum << ", число точек деления отрезка = " << numberOfSpindelsOfSegment << endl;
    simpson(thirdIntegratingFunction, 2, 7, eps, sum, numberOfSpindelsOfSegment);
    cout << "Значение третьего интеграла, вычесленное по формуле Симпсона:  "
        << sum << ", число точек деления отрезка = " << numberOfSpindelsOfSegment << endl;
}
