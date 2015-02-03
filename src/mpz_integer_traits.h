// -*- mode: c++ -*-
// Copyright (c) 2015 Olaf Dietsche

#ifndef __mpz_integer_traits_h_included__
#define __mpz_integer_traits_h_included__

#include <gmp.h>

struct mpz_integer_traits {
	static void init(mpz_t x) {
		mpz_init(x);
	}

	static void destroy(mpz_t x) {
		mpz_clear(x);
	}

	static void assign(mpz_t dest, const mpz_t src) {
		mpz_set(dest, src);
	}

	static void assign(mpz_t dest, long src) {
		mpz_set_si(dest, src);
	}

	static void assign(mpz_t dest, unsigned long src) {
		mpz_set_ui(dest, src);
	}

	static int compare(const mpz_t x, const mpz_t y) {
		return mpz_cmp(x, y);
	}

	static void add(mpz_t res, const mpz_t x, const mpz_t y) {
		mpz_add(res, x, y);
	}

	static void sub(mpz_t res, const mpz_t x, const mpz_t y) {
		mpz_sub(res, x, y);
	}

	static void mul(mpz_t res, const mpz_t x, const mpz_t y) {
		mpz_mul(res, x, y);
	}

	static void div(mpz_t res, const mpz_t x, const mpz_t y) {
		mpz_tdiv_q(res, x, y);
	}

	static void mod(mpz_t res, const mpz_t x, const mpz_t y) {
		mpz_tdiv_r(res, x, y);
	}

	static void sqrt(mpz_t res, const mpz_t x) {
		mpz_sqrt(res, x);
	}

	static void pow(mpz_t res, const mpz_t x, unsigned long y) {
		mpz_pow_ui(res, x, y);
	}

	static long to_long(const mpz_t x) {
		return mpz_get_si(x);
	}

	static char *to_string(const mpz_t x, int base) {
		return mpz_get_str(nullptr, base, x);
	}

	static void swap(mpz_t x, mpz_t y) {
		mpz_swap(x, y);
	}

	static void deallocate(void *p) {
		free(p);
	}
};

typedef basic_integer<mpz_t, mpz_integer_traits> integer;

#endif
