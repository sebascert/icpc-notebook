/**
 * Lines: [12,27]
 */
#pragma once
#include "template.hpp"

extern lli n;
extern lli a[];
extern vector<ii> g[];

extern lli dist[];
void dijkstra(int u) {
	fill(dist, dist + n, -1);
	priority_queue<ii> q;
	dist[u] = 0;
	q.push({u, 0});
	while(!q.empty()) {
		auto [u, d] = q.top();
		q.pop();
		if(dist[u] != d) continue;
		for(auto [v, i]: g[u]) {
			lli dv = d + a[i];
			if(dist[v] < 0 || dist[v] > dv)
				dist[v] = dv, q.push({v, dv});
		}
	}
}
