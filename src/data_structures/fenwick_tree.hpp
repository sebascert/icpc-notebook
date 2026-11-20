/**
 * Lines: [9,17]
 */
#pragma once
#include "template.hpp"

extern int n;
extern lli ft[];
void upd(int i0, int v) {
	for(int i = i0 + 1; i <= n; i += i & -i) ft[i] += v;
}
int get(int i0) {
	lli r = 0;
	for(int i = i0; i; i -= i & -i) r += ft[i];
	return r;
}
int get_sum(int i0, int i1) { return get(i1) - get(i0); }
