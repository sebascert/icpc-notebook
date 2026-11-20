/**
 * Lines: [10,22]
 */
#pragma once
#include "template.hpp"

extern int n;
extern vector<vector<lli>> g;

void floyd() {
	fore(w, 0, n) fore(u, 0, n) fore(v, 0, n) {
		if(g[u][w] < INF && g[w][v] < INF)
			g[u][v] = min(g[u][v], g[u][w] + g[w][v]);
	}
}

bool in_neg_cycle(int u) { return g[u][u] < 0; }
bool has_neg_cycle(int u, int v) {
	fore(w, 0, n) if(g[u][w] < INF && g[w][v] < INF &&
			 g[w][w] < 0) return true;
	return false;
}
