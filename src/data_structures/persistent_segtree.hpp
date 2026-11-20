/**
 * Lines: [7,45]
 */
#pragma once
#include "template.hpp"

struct Segtree {
#define mid ((l + r) / 2)
#define left(u) (st[u].l)
#define right(u) (st[u].r)
	struct Node {
		lli x;
		int l, r;
		Node(lli x = 0, int l = 0, int r = 0) : x(x), l(l), r(r) {}
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
	int update(int u, int l, int r, int i, lli val) {
		int v = sz(st);
		st.pb(st[u]);
		if(l == r) {
			st[v] = Node(val); // assignment
			return v;
		}
		if(i <= mid) left(v) = update(left(v), l, mid, i, val); // C++17
		else right(v) = update(right(v), mid + 1, r, i, val);	// C++17
		st[v] = st[left(v)] + st[right(v)];
		return v;
	}
	Node query(int u, int l, int r, int ll, int rr) {
		if(l > r || r < ll || l > rr) return Node();
		if(ll <= l && r <= rr) return st[u];
		return query(left(u), l, mid, ll, rr) +
		       query(right(u), mid + 1, r, ll, rr);
	}
	int update(int i, lli x, int v) { return update(v, 0, n - 1, i, x); }
	lli query(int l, int r, int v) { return query(v, 0, n - 1, l, r).x; }
};
