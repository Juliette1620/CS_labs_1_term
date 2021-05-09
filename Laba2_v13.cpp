#include <iostream>
using namespace std;

bool Proverka(int);
int SumOfDigits(int);

int main()
{
	setlocale(LC_ALL, "rus");
	int a, b, c, i, j, flag; double r, n;
	cout << "Задайте концы отрезка [a;b] натурального ряда.\n a = ";

	cin >> a;
	if (a <= 0)
	{
		cout << "Веденное значение a не является натуральным\n";
		return (1);
	}

	cout << "\n b = ";
	cin >> b;
	if (b <= 0)
	{
		cout << "Веденное значение b не является натуральным\n";
		return (1);
	}
	cout << endl;
	cout << "Простые числа, сумма цифр которых также является простым числом: \n";

	for (i = a; i <= b; i++)
	{
		if (Proverka(i) && Proverka(SumOfDigits(i)))
			cout << i << "\t";
	}

	cout << endl;

	system("pause");
	return 0;
}

bool Proverka(int a)
{
	int i, flag; double r, n;
	if ((a == 2) || (a == 3)) flag = 1;
	else
	{
		i = 2;
		flag = 1;
		r = a; n = (floor(sqrt(r)));
		while ((i <= n) && (flag))
			if (!(a % i)) flag = 0;
			else ++i;
		if (flag)
			return (true);
		else
			return (false);
	}
}

int SumOfDigits(int a)
{
	int sum = 0, component;
	while (a != 0)
	{
		sum += a % 10;
		a /= 10;
	}
	return (sum);
}
