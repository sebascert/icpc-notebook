/**
 * Lines: [10,39]
 */
#pragma once
#include "template.hpp"

extern int n;
extern vector<int> t[];

int logN;
vector<vector<int>> st;
vector<int> d;
void lca_dfs(int u, int p) {
	st[0][u] = p;
	d[u] = d[p] + 1;
	for(int v: t[u])
		if(v != p) lca_dfs(v, u);
}
void lca_init(int u) {
	logN = __lg(max(n, 1)) + 1;
	st.assign(logN, vector<int>(n + 1));
	d.assign(n + 1, 0);
	d[n] = 0;
	lca_dfs(u, n);
	fore(b, 1, logN) fore(u, 0, n) st[b][u] =
		st[b - 1][u] == n ? n : st[b - 1][st[b - 1][u]];
}
int kanc(int u, int k) {
	int x = d[u] - k;
	ford(b, logN, 0) if(d[u] - (1 << b) >= x) u = st[b][u];
	return u;
}
int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	ford(b, logN, 0) if(d[u] - (1 << b) >= d[v]) u = st[b][u];
	if(u == v) return u;
	ford(b, logN, 0) if(st[b][u] != st[b][v]) u = st[b][u], v = st[b][v];
	return st[0][u];
}
