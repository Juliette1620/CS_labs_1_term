#pragma once
#include <iostream>
#include <string>

class Fraction
{
private:
	int p_, q_;
	static int count_;
	friend void canon(Fraction&);
public:
	Fraction() : p_(0), q_(1) { ++count_; };
	Fraction(int p, int q) { if (q == 0) throw "Can't divide by 0!\n"; p_ = p; q_ = q; ++count_; };
	Fraction(const Fraction& f) { p_ = f.p_; q_ = f.q_; ++count_; }

	~Fraction() { --count_; }

	int get_q() const { return q_; };
	int get_p() const { return p_; };
	static int get_count() { return count_; };
	void set_p(int p) { p_ = p; };
	void set_q(int q) { if (q == 0) throw "Can't divide by 0!\n"; q_ = q; };
	std::string to_string()const;

	Fraction operator + (const Fraction& f)const//сложения
	{
		return Fraction(p_ * f.q_ + f.p_ * q_, q_ * f.q_);
	}
	Fraction operator + (const int i)const
	{
		return Fraction(p_ + i * q_, q_);
	}
	friend Fraction operator + (const int, const Fraction&);

	Fraction operator - ()const { return Fraction(-p_, q_); };//унарный минус

	Fraction operator - (const Fraction& f)const//разности
	{
		return Fraction(p_ * f.q_ - f.p_ * q_, q_ * f.q_);
	}
	Fraction operator - (const int i)const
	{
		return Fraction(p_ + i * q_, q_);
	}
	friend Fraction operator - (const int, const Fraction&);

	Fraction operator * (const Fraction& f)const//умножения
	{
		return Fraction(p_ * f.p_, q_ * f.q_);
	}
	Fraction operator * (const int i)const
	{
		return Fraction(p_ * i, q_);
	}
	friend Fraction operator * (const int, const Fraction&);

	Fraction operator / (const Fraction& f)const//деления
	{
		if (f.p_ == 0) throw "Can't divide by 0!\n";
		return Fraction(p_ * f.q_, q_ * f.p_);
	}
	Fraction operator / (const int i)const
	{
		if (i == 0) throw "Can't divide by 0!\n";
		return Fraction(p_, q_ * i);
	}
	friend Fraction operator / (const int, const Fraction&);

	Fraction& operator = (const Fraction&);//присваивания
	Fraction& operator = (const int);
	Fraction& operator += (const Fraction&);
	Fraction& operator += (const int);
	Fraction& operator -= (const Fraction&);
	Fraction& operator -= (const int);
	Fraction& operator *= (const Fraction&);
	Fraction& operator *= (const int);
	Fraction& operator /= (const Fraction&);
	Fraction& operator /= (const int);

	bool operator == (const Fraction& f)const//сравнения
	{
		return ((p_ * 1.0 / q_) == (f.p_ * 1.0 / f.q_));
	}
	bool operator > (const Fraction& f)const
	{
		return ((p_ * 1.0 / q_) > (f.p_ * 1.0 / f.q_));
	}
	bool operator < (const Fraction& f)const
	{
		return ((p_ * 1.0 / q_) < (f.p_ * 1.0 / f.q_));
	}
	bool operator != (const Fraction& f)const
	{
		return ((p_ * 1.0 / q_) != (f.p_ * 1.0 / f.q_));
	}

	Fraction& operator++()//инкременты
	{
		p_ += q_;
		return (*this);
	}
	Fraction& operator--()
	{
		p_ -= q_;
		return (*this);
	}
	Fraction operator++(int)
	{
		Fraction f(*this);
		p_ += q_;
		return f;
	}
	Fraction operator--(int)
	{
		Fraction f(*this);
		p_ -= q_;
		return f;
	}
	friend std::ostream& operator << (std::ostream&, const Fraction&);//Вывод в выходной поток
};