// -*- mode: c++ -*-
#ifndef __matrix_h_included__
#define __matrix_h_included__

// Copyright (c) 2015 Olaf Dietsche

template<size_t N, size_t M, typename T> struct basic_matrix {
	T entries[N][M];

	basic_matrix();
	basic_matrix(std::initializer_list<T> init);
	basic_matrix &operator+=(const basic_matrix &x);
	template<size_t P> basic_matrix<N, P, T> &operator*=(const basic_matrix<M, P, T> &x);
};

template<size_t N, size_t M, typename T> basic_matrix<N, M, T>::basic_matrix()
{
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j)
			entries[i][j] = 0;
	}
}

template<size_t N, size_t M, typename T> basic_matrix<N, M, T>::basic_matrix(std::initializer_list<T> init)
{
	auto k = init.begin();
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j)
			entries[i][j] = *k++;
	}
}

template<size_t N, size_t M, typename T> basic_matrix<N, M, T> &basic_matrix<N, M, T>::operator+=(const basic_matrix<N, M, T> &x)
{
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j)
			entries[i][j] += x.entries[i][j];
	}

	return *this;
}

template<size_t N, size_t M, typename T> basic_matrix<N, M, T> operator+(basic_matrix<N, M, T> x, const basic_matrix<N, M, T> &y) 
{
	return x += y;
}

template<size_t N, size_t M, typename T> basic_matrix<N, M, T> operator*(T n, basic_matrix<N, M, T> x)
{
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j)
			x.entries[j][i] *= n;
	}

	return x;
}

template<size_t N, size_t M, typename T> basic_matrix<N, M, T> operator*(const basic_matrix<N, M, T> &x, T n)
{
	return n * x;
}

template<size_t N, size_t M, size_t P, typename T> basic_matrix<N, P, T> operator*(const basic_matrix<N, M, T> &x, const basic_matrix<M, P, T> &y)
{
	basic_matrix<N, P, T> res;
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < P; ++j) {
			res.entries[i][j] = 0;
			for (size_t k = 0; k < M; ++k)
				res.entries[i][j] += x.entries[i][k] * y.entries[k][j];
		}
	}

	return res;
}


template<size_t N, size_t M, typename T> template<size_t P> basic_matrix<N, P, T> &basic_matrix<N, M, T>::operator*=(const basic_matrix<M, P, T> &x)
{
	return *this = *this * x;
}

template<size_t N, size_t M, typename T> basic_matrix<M, N, T> transpose(const basic_matrix<N, M, T> &x)
{
	basic_matrix<M, N, T> res;
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j)
			res.entries[j][i] = x.entries[i][j];
	}

	return res;
}

template<size_t N, typename T, typename I = size_t> basic_matrix<N, N, T> pow(const basic_matrix<N, N, T> &x, I n)
{
	basic_matrix<N, N, T> res = x;
	I rem = 0, i = 1;
	for (; n >= 2; n /= 2, i *= 2) {
		if (n % 2 == 1)
			rem += i;

		res = res * res;
	}

	if (rem > 0)
		res *= pow(x, rem);

	return res;
}

#endif
