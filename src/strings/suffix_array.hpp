/**
 * Lines: [8,23]
 */
#pragma once
#include "template.hpp"

extern ii sf[];
bool sacomp(int l, int r) { return sf[l] < sf[r]; }
vector<int> suffix_array(string& s) { // O(Nlog^2(N))
	s += '$';
	int n = sz(s);
	vector<int> sa(n), r(n);
	fore(i, 0, n) r[i] = s[i];
	for(int k = 1; k < n; k *= 2) {
		fore(i, 0, n) sa[i] = i,
			      sf[i] = {r[i], i + k < n ? r[i + k] : -1};
		stable_sort(all(sa), sacomp);
		r[sa[0]] = 0;
		fore(i, 1, n) r[sa[i]] =
			sf[sa[i]] != sf[sa[i - 1]] ? i : r[sa[i - 1]];
	}
	return sa;
}
