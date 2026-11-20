/**
 * Lines: [7,27]
 */
#pragma once
#include "template.hpp"

// https://codeforces.com/blog/entry/68953

// count of xor-sum = x is 2^(n-nb)
const int K = 0;
lli nb, basis[K]; // basis[i] has the vector with pivot at i
void insert_vector(lli v) {
	fore(i, 0, K) { // LSB
		if(~v & (1ll << i)) continue;
		if(!basis[i]) {
			basis[i] = v;
			nb++;
			return;
		}
		v ^= basis[i];
	}
}

bool has_vector(lli v) {
	fore(i, 0, K) if((v >> i) & 1) v ^= basis[i];
	return v == 0;
}
