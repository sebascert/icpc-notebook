/**
 * Lines: [7,59]
 */
#pragma once
#include "template.hpp"

struct Aho {
	const static int K = 26;
	int idx(char c) { return c - 'a'; }
	struct Node {
		vector<int> leaf;
		int p, pch, ln, out, next[K], go[K];
		Node(int p = -1, int pch = -1)
		    : p(p), pch(pch), ln(-1), out(-1) {
			memset(next, 0, sizeof(next));
			memset(go, -1, sizeof(go));
		}
	};
	vector<Node> t;
	Aho() : t(1) {}
	void add(string& s, int i) {
		int u = 0;
		for(int c: s) {
			c = idx(c);
			if(!t[u].next[c]) {
				t[u].next[c] = t[u].go[c] = sz(t);
				t.emplace_back(u, c);
			}
			u = t[u].next[c];
		}
		t[u].leaf.pb(i);
	}
	int get_link(int u) {
		if(t[u].ln < 0) {
			t[u].ln = !u || !t[u].p ?
					  0 :
					  go(get_link(t[u].p), t[u].pch);
			// if(u) {
			// 	int v = t[u].ln;
			// 	get_link(v);
			// 	t[u].leaf.insert(t[u].leaf.end(),
			// all(t[v].leaf));
			// }
		}
		return t[u].ln;
	}
	int get_dict(int u) {
		if(t[u].out < 0) {
			int v = get_link(u);
			t[u].out = !v ? 0 : (sz(t[v].leaf) ? v : get_dict(v));
		}
		return t[u].out;
	}
	int go(int u, int c) {
		if(t[u].go[c] < 0) t[u].go[c] = !u ? 0 : go(get_link(u), c);
		return t[u].go[c];
	}
	int go(int u, char c) { return go(u, idx(c)); }
};
