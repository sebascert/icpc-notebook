/**
 * Lines: [7,50]
 */
#pragma once
#include "template.hpp"

struct Segtree {
#define mid ((l + r) / 2)
#define left(u) (u + 1)
#define right(u) (u + 2 * (mid - l + 1))
#define NOP 0
	struct Node {
		lli x, lazy;
		Node(lli x = 0) : x(x), lazy(NOP) {}
		Node operator+(const Node& n) { return Node(x + n.x); }
	};
	int n;
	vector<Node> st;
	Segtree(int n) : n(n), st(2 * n) {}
	void push(int u, int l, int r) {
		if(st[u].lazy == NOP) return;
		if(l < r) {
			st[left(u)].lazy += st[u].lazy;
			st[right(u)].lazy += st[u].lazy;
		}
		st[u].x += st[u].lazy * (r - l + 1);
		st[u].lazy = NOP;
	}
	void update(int u, int l, int r, int ll, int rr, lli val) {
		push(u, l, r);
		if(l > r || r < ll || l > rr) return;
		if(ll <= l && r <= rr) {
			st[u].lazy += val;
			push(u, l, r);
			return;
		}
		update(left(u), l, mid, ll, rr, val);
		update(right(u), mid + 1, r, ll, rr, val);
		st[u] = st[left(u)] + st[right(u)];
	}
	Node query(int u, int l, int r, int ll, int rr) {
		push(u, l, r);
		if(l > r || r < ll || l > rr) return Node();
		if(ll <= l && r <= rr) return st[u];
		return query(left(u), l, mid, ll, rr) +
		       query(right(u), mid + 1, r, ll, rr);
	}
	void update(int l, int r, lli val) { update(0, 0, n - 1, l, r, val); }
	lli query(int l, int r) { return query(0, 0, n - 1, l, r).x; }
};
