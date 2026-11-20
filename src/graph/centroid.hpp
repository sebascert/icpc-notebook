/**
 * Lines: [12,35]
 */
#pragma once
#include "template.hpp"

extern int n;
extern vector<int> t[];

extern bool tk[];
extern int fat[], szt[];
int calcsz(int x, int f) {
	szt[x] = 1;
	for(auto y: t[x])
		if(y != f && !tk[y]) szt[x] += calcsz(y, x);
	return szt[x];
}
void cdfs(int x = 0, int f = -1, int sz = -1) {
	if(sz < 0) sz = calcsz(x, -1);
	for(auto y: t[x])
		if(!tk[y] && szt[y] * 2 >= sz) {
			szt[x] = 0;
			cdfs(y, f, sz);
			return;
		}
	// solve(x)
	tk[x] = true;
	fat[x] = f;
	for(auto y: t[x])
		if(!tk[y]) cdfs(y, x);
}
void centroid() {
	fill(tk, tk + n, false);
	cdfs();
}
