/**
 * Lines: [7,18]
 */
#pragma once
#include "template.hpp"

void div_rec(vi& r, vector<ii>& f, int k, lli c) {
	if(k == sz(f)) {
		r.push_back(c);
		return;
	}
	fore(i, 0, f[k].s + 1) div_rec(r, f, k + 1, c), c *= f[k].f;
}
vi divisors(vector<ii> f) {
	vi r;
	div_rec(r, f, 0, 1);
	return r;
}
