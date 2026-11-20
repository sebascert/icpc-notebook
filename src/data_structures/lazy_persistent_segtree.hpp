/**
 * Lines: [7,66]
 */
#pragma once
#include "template.hpp"

struct Segtree {
#define mid ((l + r) / 2)
#define left(u) (st[u].l)
#define right(u) (st[u].r)
#define NOP 0
	struct Node {
		lli x, lazy;
		int l, r;
		Node(lli x = 0, int l = 0, int r = 0)
		    : x(x), lazy(NOP), l(l), r(r) {}
		Node operator+(const Node& n) { return Node(x + n.x); }
		Node(const Node&) = default;
		Node& operator=(const Node& n) {
			x = n.x;
			return *this;
		}
	};
	int n;
	vector<Node> st;
	Segtree(int n) : n(n), st(1) {}
	void push(int u, int l, int r) {
		if(st[u].lazy == NOP) return;
		if(l < r) {
			int vl = sz(st);
			st.pb(st[left(u)]);
			st[left(u) = vl].lazy += st[u].lazy;
			int vr = sz(st);
			st.pb(st[right(u)]);
			st[right(u) = vr].lazy += st[u].lazy;
		}
		st[u].x += (r - l + 1) * st[u].lazy;
		st[u].lazy = 0;
	}
	int update(int u, int l, int r, int ll, int rr, lli val) {
		push(u, l, r);
		if(l > r || r < ll || l > rr) return u;
		int v = sz(st);
		st.pb(st[u]);
		if(ll <= l && r <= rr) {
			st[v].lazy += val;
			push(v, l, r);
			return v;
		}
		left(v) = update(left(v), l, mid, ll, rr, val);
		right(v) = update(right(v), mid + 1, r, ll, rr, val);
		st[v] = st[left(v)] + st[right(v)];
		return v;
	}
	Node query(int u, int l, int r, int ll, int rr) {
		push(u, l, r);
		if(l > r || r < ll || l > rr) return Node();
		if(ll <= l && r <= rr) return st[u];
		return query(left(u), l, mid, ll, rr) +
		       query(right(u), mid + 1, r, ll, rr);
	}
	int update(int l, int r, lli x, int v) {
		return update(v, 0, n - 1, l, r, x);
	}
	lli query(int l, int r, int v) { return query(v, 0, n - 1, l, r).x; }
};
