/**
 * Lines: [12,19]
 */
#pragma once
#include "template.hpp"

extern int n;
extern int a[];
extern vector<ii> g[];

extern lli dist[];
void bford(int u) {
	fill(dist, dist + n, INF);
	dist[u] = 0;
	fore(i, 0, n) fore(u, 0, n) if(dist[u] != INF) for(auto [v, i]: g[u])
		dist[v] = min(dist[v], dist[u] + a[i]);
	// neg cycle all reachable from v have -INF dist
	// fore(u,0,n)if(dist[u]!=INF)for(auto[v,i]:g[u])if(dist[v]>dist[u]+a[i]);
}
