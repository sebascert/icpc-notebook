/**
 * Lines: [16,37]
 */
#pragma once
#include "template.hpp"

extern void init();
extern void add(int i);
extern void rem(int i);
extern lli ans();
struct qu;
extern qu qs[];
extern lli qq[];
extern int n, nq; // array size and #queries

struct qu {
	int l, r, id;
};
int sq;
bool qcomp(const qu& a, const qu& b) {
	if(a.l / sq != b.l / sq) return a.l < b.l;
	return (a.l / sq) & 1 ? a.r < b.r : a.r > b.r;
}
void mos() {
	sq = sqrt(n) + .5;
	sort(qs, qs + nq, qcomp);
	init();
	int l = 0, r = 0;
	fore(i, 0, nq) {
		qu q = qs[i];
		while(l > q.l) add(--l);
		while(r < q.r) add(r++);
		while(l < q.l) rem(l++);
		while(r > q.r) rem(--r);
		qq[q.id] = ans();
	}
}
