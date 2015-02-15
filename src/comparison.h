// -*- mode: c++ -*-
#ifndef __comparison_h_included__
#define __comparison_h_included__

// Copyright (c) 2015 Olaf Dietsche

template<typename T1, typename T2> static inline bool operator>(const T1 &x, const T2 &y) {
	return y < x;
}

template<typename T1, typename T2> static inline bool operator<=(const T1 &x, const T2 &y) {
	return !(y < x); 
}

template<typename T1, typename T2> static inline bool operator>=(const T1 &x, const T2 &y) {
	return !(x < y); 
}

template<typename T1, typename T2> static inline bool operator==(const T1 &x, const T2 &y) {
	return !(x < y) && !(y < x);
}

template<typename T1, typename T2> static inline bool operator!=(const T1 &x, const T2 &y) {
	return !(y == x);
}

#endif
