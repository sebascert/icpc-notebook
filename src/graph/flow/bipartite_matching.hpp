/**
 * Lines: [7,43]
 */
#pragma once
#include "template.hpp"

struct Matching {
	int n;
	vector<vector<int>> g;
	vector<int> l, r, d;
	Matching(int n, int m) : n(n), g(n), l(n, -1), r(m, -1) {}
	void add(int u, int v) { g[u].pb(v); }
	void bfs() {
		d.assign(n, -1);
		queue<int> q;
		fore(u, 0, n) if(l[u] < 0) d[u] = 0, q.push(u);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int v: g[u])
				if(r[v] >= 0 && d[r[v]] < 0)
					d[r[v]] = d[u] + 1, q.push(r[v]);
		}
	}
	bool dfs(int u) {
		for(int v: g[u]) {
			int w = r[v];
			if(w < 0 || (d[w] == d[u] + 1 && dfs(w)))
				return l[u] = v, r[v] = u, 1;
		}
		return d[u] = -1, 0;
	}
	int matching() {
		int x = 0, y;
		do {
			bfs();
			y = 0;
			fore(u, 0, n) if(l[u] < 0) y += dfs(u);
			x += y;
		} while(y);
		return x;
	}
};
