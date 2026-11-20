/**
 * Lines: [7,19]
 */
#pragma once
#include "template.hpp"

struct DSU {
	vector<int> pr, rank;
	DSU(int n) : pr(n), rank(n, 1) { iota(all(pr), 0); }
	int find(int u) { return pr[u] == u ? u : pr[u] = find(pr[u]); }
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if(u == v) return false;
		if(rank[u] < rank[v]) swap(u, v);
		pr[v] = u;
		rank[u] += rank[v];
		return true;
	}
};
