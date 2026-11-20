/**
 * Lines: [13,37]
 */
#pragma once
#include "data_structures/dsu.hpp"
#include "template.hpp"

extern int n;
extern vector<int> t[];

extern int d[], art[];

DSU dsu(0);
int dfs(int u, int p) {
	int dp = d[u] = d[p] + 1;
	for(int v: t[u]) {
		if(v == p) continue;
		if(!d[v]) { // span edge
			dp = min(dp, dfs(v, u));
		} else if(d[v] < d[u]) { // back edge
			dp = min(dp, d[v]);
		}
	}
	art[p] += dp >= d[p];
	if(p != n) {
		if(dp <= d[u]) { // bridge (u,p)
		} else {
			dsu.unite(u, p);
		}
	} else art[u]--; // root
	return dp;
}
void art_bri_bic() {
	d[n] = 0;
	dsu = DSU(n);
	dfs(0, n);
}
