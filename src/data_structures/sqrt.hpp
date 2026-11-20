/**
 * Lines: [12,31]
 */
#pragma once
#include "template.hpp"

extern int a[];
extern int n;

extern lli sq[];
extern int who[];
int block;

template <class T> T query(int l, int r) {
	T x = {};
	while(l <= r) {
		if(l % block == 0 && l + block - 1 <= r) {
			x += sq[who[l]];
		} else {
			x += a[l++];
		}
	}
	return x;
}
void do_sqrt_decomposition() {
	block = sqrt(n);
	fore(i, 0, n) {
		who[i] = i / block;
		sq[who[i]] += a[i];
	}
}
