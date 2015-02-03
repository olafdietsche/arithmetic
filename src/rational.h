// -*- mode: c++ -*-
// Copyright (c) 2015 Olaf Dietsche

#ifndef __rational_h_included__
#define __rational_h_included__

#include <iostream>

template<typename Rep> class basic_rational {
public:
	friend bool operator==(const basic_rational &x, const basic_rational &y) {
		return x.numerator_ * y.denominator_ == y.numerator_ * x.denominator_;
	}

	friend bool operator<(const basic_rational &x, const basic_rational &y) {
		return x.numerator_ * y.denominator_ < y.numerator_ * x.denominator_;
	}

	friend basic_rational operator+(const basic_rational &x, const basic_rational &y) {
		return basic_rational{x.numerator_ * y.denominator_ + y.numerator_ * x.denominator_, x.denominator_ * y.denominator_};
	}

	friend basic_rational operator*(const basic_rational &x, const basic_rational &y) {
		return basic_rational{x.numerator_ * y.numerator_, x.denominator_ * y.denominator_};
	}

	friend basic_rational operator/(const basic_rational &x, const basic_rational &y) {
		return basic_rational{x.numerator_ * y.denominator_, x.denominator_ * y.numerator_};
	}

	friend basic_rational operator+(long x, const basic_rational &y) {
		return basic_rational{x * y.denominator_ + y.numerator_, y.denominator_};
	}

	friend basic_rational operator/(long x, const basic_rational &y) {
		return basic_rational{x * y.denominator_, y.numerator_};
	}

	friend std::ostream &operator<<(std::ostream &f, const basic_rational &x) {
		return f << x.numerator_ << '/' << x.denominator_;
	}

	basic_rational(const Rep &num, const Rep &den)
		: numerator_(num), denominator_(den) {}

	const Rep &numer() const { return numerator_; }
	const Rep &denom() const { return denominator_; }

	basic_rational &operator+=(long n) {
		numerator_ += n * denominator_;
		return *this;
	}

	basic_rational &reduce() {
		Rep d = gcd(numerator_, denominator_);
		numerator_ /= d, denominator_ /= d;
		return *this;
	}
private:
	Rep numerator_, denominator_;
};

template<typename Rep> basic_rational<Rep> reduce(basic_rational<Rep> f) {
	return f.reduce();
}

#endif
