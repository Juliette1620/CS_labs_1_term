#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	double eps, x, sum, component, n;
	int i;
	const double pi = 3.1415926535;
	for (;;)
	{
		cout << "Введите аргумент Х удовлетворяющий условию х > 1 \n";
		cin >> x;
		if (x <= 1)
			cout << "Значение Х не удовлетворяет условию x > 1 \n";
		else
			break;
	}
	for (;;)
	{
		cout << "Введите значение точности Е удовлетворяющее условию 0 < eps < 10^(-k) \n";
		cin >> eps;
		if (eps >= 1 || eps <= 0)
			cout << "Значение E не удовлетворяет условию 0 < eps < 10^(-k)\n";
		else
			break;
	}
	component = -1 / x;
	sum = pi / 2;
	n = 0;
	while (fabs(component) >= eps)
	{
		sum += component;
		++n;
		component = (-1) * component * (2 * n - 1) / ((2 * n + 1) * x * x);

	}
	cout << endl;
	cout << "Ответ:\n";
	cout.precision(10);
	cout << "arctg(x)= " << atan(x) << "\t Сумма ряда: sum = " << sum;
	cout << endl;
	system("pause");
		
}