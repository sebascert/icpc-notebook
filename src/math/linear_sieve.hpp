/**
 * Lines: [7,27]
 */
#pragma once
#include "template.hpp"

const int K = 0 + 1;
int lp[K];
vector<int> pr;
void sieve() {
	fore(i, 2, K) {
		if(lp[i] == 0) {
			lp[i] = i;
			pr.pb(i);
		}
		for(int j = 0; i * pr[j] < K; j++) {
			lp[i * pr[j]] = pr[j];
			if(pr[j] == lp[i]) break;
		}
	}
}

vi fact(lli x) {
	vi f;
	while(x > 1) f.pb(lp[x]), x /= lp[x];
	return f;
}
