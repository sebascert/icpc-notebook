/**
 * Lines: [12,62]
 */
#pragma once
#include "template.hpp"

extern int n;
extern vector<int> g[];

extern int lw[], idx[], cmp[];

// bool truth[n]; (2SAT)
// int nvar;
// int neg(int x) { return n - 1 - x; }

int qidx, qcmp;
stack<int> st;
void tjn(int u) {
	lw[u] = idx[u] = ++qidx;
	st.push(u);
	cmp[u] = -2;
	for(int v: g[u]) {
		if(!idx[v] || cmp[v] == -2) {
			if(!idx[v]) tjn(v);
			lw[u] = min(lw[u], lw[v]);
		}
	}
	if(lw[u] == idx[u]) {
		int x;
		// int l = -1; (2SAT)
		do {
			x = st.top();
			st.pop();
			cmp[x] = qcmp;
			// if (min(x, neg(x)) < nvar) (2SAT)
			// 	l = x;
		} while(x != u);
		// if (l != -1) (2SAT)
		// 	truth[qcmp] = cmp[neg(l)] < 0;
		qcmp++;
	}
}
vector<int> crep;
void scc() {
	fill(idx, idx + n, 0);
	qidx = 0;
	fill(cmp, cmp + n, -1);
	qcmp = 0;
	fore(i, 0, n) if(!idx[i]) tjn(i);

	crep.resize(qcmp);
	fore(u, 0, n) crep[cmp[u]] = u;
}

// void addor(int a, int b) { g[neg(a)].pb(b), g[neg(b)].pb(a); } (2SAT)
// bool satisfy(int _nvar) {
// 	nvar = _nvar;
// 	n = nvar;
// 	scc();
// 	fore(i, 0, nvar) if (cmp[i] == cmp[neg(i)]) return false;
// 	return true;
// }
