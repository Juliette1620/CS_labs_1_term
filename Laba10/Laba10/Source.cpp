#include "Header.h"
#include <iostream>
#include <string>

int Fraction::count_ = 0;

std::string Fraction::to_string()const {
	Fraction f1(*this);
	canon(f1);
	std::string res = std::to_string(f1.p_);
	res = res + " / " + std::to_string(f1.q_);
	return  "(" + res + ")";
}
Fraction operator + (const int i, const Fraction& f) {
	return Fraction(f.p_ + i * f.q_, f.q_);
}

Fraction operator - (const int i, const Fraction& f) {
	return Fraction(i * f.q_ - f.p_, f.q_);
}

Fraction operator * (const int i, const Fraction& f) {
	return Fraction(i * f.p_, f.q_);
}

Fraction operator / (const int i, const Fraction& f) {
	if (f.p_ == 0) throw "Can't divide by 0!\n";
	return Fraction(i * f.q_, f.p_);
}

Fraction& Fraction::operator = (const Fraction& f) {
	if (&f != this) {
		p_ = f.p_;
		q_ = f.q_;
	}
	return *this;
}
Fraction& Fraction::operator = (const int i) {
	p_ = i;
	q_ = 1;
	return *this;
}
Fraction& Fraction::operator += (const Fraction& f) {
	p_ = p_ * f.q_ + f.p_ * q_;
	q_ = q_ * f.q_;
	return *this;
}
Fraction& Fraction::operator += (const int i) {
	p_ += i * q_;
	return *this;
}
Fraction& Fraction::operator -= (const Fraction& f) {
	p_ = p_ * f.q_ - f.p_ * q_;
	q_ = q_ * f.q_;
	return *this;
}
Fraction& Fraction::operator -= (const int i) {
	p_ -= i * q_;
	return *this;
}
Fraction& Fraction::operator *= (const Fraction& f) {
	p_ *= f.p_;
	q_ *= f.q_;
	return *this;
}
Fraction& Fraction::operator *= (const int i) {
	p_ *= i;
	return *this;
}
Fraction& Fraction::operator /= (const Fraction& f) {
	if (f.p_ == 0) throw  "Can't divide by 0!\n";
	p_ *= f.q_;
	q_ *= f.p_;
	return *this;
}
Fraction& Fraction::operator /= (const int i) {
	if (i == 0) throw  "Can't divide by 0!\n";
	q_ *= i;
	return *this;
}

std::ostream& operator << (std::ostream& os, const Fraction& f) {
	os << f.to_string();
	return os;
}

void canon(Fraction& f) {
	int a1 = f.get_p(), b1 = f.get_q(), r, b = abs(b1), a = abs(a1);
	if (a1 < b1) {
		int temp = b;
		b = a;
		a = temp;
	}
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	if (b1 < 0) {
		b1 = -b1;
		a1 = -a1;
	}
	f.set_p(a1 / a);
	f.set_q(b1 / a);
}