#include "Header.h"
#include <ctime>
#include <iostream>
#include <cstring>

int main() {
	Fraction f1, f2(1, 13), f3(45, 90);
	//Сумма
	f1 = f2 + f3;
	std::cout << "SUMM\n" << f2 << " + " << f3 << " = " << f1 << "\n";

	f1.set_p(0); f1.set_q(1);
	//Составная операция присваивания
	std::cout << "Compound assignment\n" << ((f1 -= Fraction(1, 3)) += Fraction(1, 2)) << "\n";
	std::cout << ((f1 *= Fraction(1, 3)) /= Fraction(10, 18)) << "\n";
	f1 = -5 + Fraction(36, 4);
	std::cout << f1 << "\n";
	std::cout << "Number of objects:\n" << Fraction::get_count() << "\n\n";
	Fraction* f4 = new Fraction(0, 1);
	std::cout << "Number of objects:\n" << Fraction::get_count() << "\n\n";
	std::cout << *f4 << "\n";
	std::cout << ++ * f4 << "\n";
	std::cout << ++(++(++ * f4)) << "\n";
	std::cout << (*f4)++ << "\n";
	std::cout << (*f4)-- << "\n";
	std::cout << *f4 << "\n";
	delete f4;
	std::cout << "Number of objects:\n" << Fraction::get_count() << "\n\n";
	//Разность, произведение, деление
	f1 = f2 - f3;
	std::cout << "MINUS\n" << f2 << " - " << f3 << " = " << f1 << "\n";
	f1 = f2 * f3;
	std::cout << "MULT\n" << f2 << " * " << f3 << " = " << f1 << "\n";
	try {
		f1 = f2 / f3;
		std::cout << "DIV\n" << f2 << " / " << f3 << " = " << f1 << "\n";
	}
	catch (const char* s) {
		std::cout << s << "\n";
	}
	std::cout << f1 << " == " << f2 << " - " << (f1 == f2 ? "true" : "false") << "\n";
	std::cout << f1 << " != " << f2 << " - " << (f1 != f2 ? "true" : "false") << "\n";
	std::cout << f1 << " > " << f2 << " - " << (f1 > f2 ? "true" : "false") << "\n";
	std::cout << f1 << " < " << f2 << " - " << (f1 < f2 ? "true" : "false") << "\n";
	//создадим массив и заполним случайными числами, затем отсортируем и выведем на экран
	const int n = 10;
	Fraction mas[n];
	std::cout << "Number of objects:\n" << Fraction::get_count() << "\n\n";
	std::cout << "Array\n";
	srand(time(0));
	for (int i = 0; i < n; i++) {
		mas[i].set_p(rand() % n);
		mas[i].set_q(rand() % n + 1);
		std::cout << mas[i] << "\n";
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (mas[j] > mas[j + 1]) {
				Fraction temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
	std::cout << "Number of objects:\n" << Fraction::get_count() << "\n\n";
	std::cout << "Sorted array\n";
	for (int i = 0; i < n; i++)
		std::cout << mas[i] << "\n";
	try {
		Fraction randomf(1, 0);
	}
	catch (const char* str) {
		std::cout << str;
	}
	return 0;
}