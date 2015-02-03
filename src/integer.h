// -*- mode: c++ -*-
// Copyright (c) 2015 Olaf Dietsche

#ifndef __integer_h_included__
#define __integer_h_included__

#include <iostream>

template<typename Rep, typename Traits> class basic_integer {
public:
	friend std::ostream &operator<<(std::ostream &f, const basic_integer &x) {
		char *s = Traits::to_string(x.rep_, 10);
		f << s;
		Traits::deallocate(s);
		return f;
	}

	friend basic_integer operator+(const basic_integer &x, const basic_integer &y) {
		basic_integer res;
		Traits::add(res.rep_, x.rep_, y.rep_);
		return res;
	}

	friend basic_integer operator-(const basic_integer &x, const basic_integer &y) {
		basic_integer res;
		Traits::sub(res.rep_, x.rep_, y.rep_);
		return res;
	}

	friend basic_integer operator*(const basic_integer &x, const basic_integer &y) {
		basic_integer res;
		Traits::mul(res.rep_, x.rep_, y.rep_);
		return res;
	}

	friend basic_integer operator/(const basic_integer &x, const basic_integer &y) {
		basic_integer res;
		Traits::div(res.rep_, x.rep_, y.rep_);
		return res;
	}

	friend basic_integer operator%(const basic_integer &x, const basic_integer &y) {
		basic_integer res;
		Traits::mod(res.rep_, x.rep_, y.rep_);
		return res;
	}

	friend bool operator==(const basic_integer &x, const basic_integer &y) {
		return Traits::compare(x.rep_, y.rep_) == 0;
	}

	friend bool operator<(const basic_integer &x, const basic_integer &y) {
		return Traits::compare(x.rep_, y.rep_) < 0;
	}

	friend std::string to_string(const basic_integer &x, int base = 10) {
		char *p = Traits::to_string(x.rep_, base);
		std::string s(p);
		Traits::deallocate(p);
		return s;
	}

	friend basic_integer sqrt(const basic_integer &x) {
		basic_integer r;
		Traits::sqrt(r.rep_, x.rep_);
		return r;
	}

	friend basic_integer pow(const basic_integer &x, unsigned long y) {
		basic_integer r;
		Traits::pow(r.rep_, x.rep_, y);
		return r;
	}

	basic_integer(int i = 0)
		: basic_integer(static_cast<long>(i)) {
	}

	basic_integer(unsigned i)
		: basic_integer(static_cast<long>(i)) {
	}

	basic_integer(long i) {
		Traits::init(rep_);
		Traits::assign(rep_, i);
	}

	basic_integer(unsigned long i) {
		Traits::init(rep_);
		Traits::assign(rep_, i);
	}

	basic_integer(const basic_integer &i) {
		Traits::init(rep_);
		Traits::assign(rep_, i.rep_);
	}

	basic_integer(basic_integer &&i) {
		Traits::init(rep_);
		Traits::swap(rep_, i.rep_);
	}

	~basic_integer() {
		Traits::destroy(rep_);
	}

	basic_integer &operator=(const basic_integer &x) {
		Traits::assign(rep_, x.rep_);
		return *this;
	}

	basic_integer &operator=(basic_integer &&x) {
		Traits::swap(rep_, x.rep_);
		return *this;
	}

	basic_integer &operator+=(const basic_integer &i) {
		*this = *this + i;
		return *this;
	}

	basic_integer &operator-=(const basic_integer &i) {
		*this = *this - i;
		return *this;
	}

	basic_integer &operator*=(const basic_integer &i) {
		*this = *this * i;
		return *this;
	}

	basic_integer &operator/=(const basic_integer &i) {
		*this = *this / i;
		return *this;
	}

	basic_integer &operator++() { return *this += 1; }

	basic_integer operator++(int) {
		basic_integer tmp(*this);
		*this += 1;
		return tmp;
	}

	basic_integer &operator--() { return *this -= 1; }

	basic_integer operator--(int) {
		basic_integer tmp(*this);
		*this -= 1;
		return tmp;
	}

	explicit operator long() const {
		return Traits::to_long(rep_);
	}
private:
	Rep rep_;
};

#endif
