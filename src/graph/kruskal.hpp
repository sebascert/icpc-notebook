/**
 * Lines: [11,22]
 */
#pragma once
#include "data_structures/dsu.hpp"
#include "template.hpp"

extern int n, m;
extern vector<ii> g[];

lli mst() {
	vector<vi> e;
	fore(u, 0, n) for(auto [v, w]: g[u]) e.pb({w, u, v});
	sort(all(e));
	DSU dsu(n);
	lli x = 0;
	fore(i, 0, m) {
		lli u = e[i][1], v = e[i][2], w = e[i][0];
		if(dsu.unite(u, v)) x += w;
	}
	return x;
}
