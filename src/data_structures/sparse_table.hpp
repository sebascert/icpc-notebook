/**
 * Lines: [9,21]
 */
#pragma once
#include "template.hpp"

extern int n;

const int N = 1, logN = __lg(N);

#define oper(x, y) min((x), (y))
lli st[logN][N];
void st_init(lli* a) {
	fore(i, 0, n) st[0][i] = a[i];
	fore(k, 1, logN) fore(i, 0, n - (1 << k) + 1) st[k][i] =
		oper(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
}
lli st_query(int l, int r) { //[l,r]
	int k = 31 - __builtin_clz(r - l + 1);
	return oper(st[k][l], st[k][r + 1 - (1 << k)]);
}
