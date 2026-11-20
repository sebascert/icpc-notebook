/**
 * Lines: [9,32]
 */
#pragma once
#include "template.hpp"

extern int N;
extern lli fact[];
const int mod = 1e9 + 7;

lli binexp(lli a, lli b) {
	a %= mod;
	lli x = 1;
	while(b > 0) {
		if(b & 1) x = x * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return x;
}
lli inv(lli x) { return binexp(x, mod - 2); }
lli comb(lli n, lli k) {
	if(k >= n) return 1;
	return fact[n] * inv(fact[k]) % mod * inv(fact[n - k]) % mod;
}
void prep() {
	fact[0] = 1;
	fore(i, 1, N) fact[i] = i * fact[i - 1] % mod;
}

lli boxball_rep(lli n, lli k) { return comb(k + n - 1, k); }
lli catalan(lli n) { return comb(2 * n, n) * inv(n + 1) % mod; }
