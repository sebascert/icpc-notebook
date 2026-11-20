/**
 * Lines: [9,34]
 */
#pragma once
#include "template.hpp"

extern bool f(R x);

using R = double;
using U = uint64_t;

#define bcv(x, y) memcpy(&y, &x, sizeof(y));
const U SBIT = ((U)1 << (sizeof(U) * 8 - 1));
U encode(R x) {
	U y;
	bcv(x, y);
	return (y & SBIT) ? ~y : y ^ SBIT;
}
R decode(U x) {
	R y;
	x = (x & SBIT) ? x ^ SBIT : ~x;
	bcv(x, y);
	return y;
}

R rbsearch(R l, R r) {
	// assert(sizeof(R) == sizeof(U));
	U ll = encode(l), rr = encode(r);
	while(rr - ll > 1) {
		U m = ll + (rr - ll) / 2;
		(f(decode(m)) ? rr : ll) = m;
	}
	return decode(ll);
}
