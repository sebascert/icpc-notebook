/**
 * Lines: [7,84]
 */
#pragma once
#include "template.hpp"

// https://codeforces.com/blog/entry/97627

const int mod = 1e9 + 7, logK = 0;

lli binexp(lli a, lli b) {
	a %= mod;
	lli r = 1;
	while(b) {
		if(b & 1) r = r * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return r;
}
lli inv(lli x) { return binexp(x, mod - 2); }

struct LinearRec {
	typedef vector<int> vi;
	lli n;
	vi terms, trans;
	vector<vi> bin;
	LinearRec(vi& seq) : terms(seq), trans(BM(seq)) { init(); }
	LinearRec(vi& terms, vi& trans) : terms(terms), trans(trans) { init(); }
	void init() { // O(N^2logK)
		n = sz(trans);
		vi x(n + 1);
		x[1] = 1;
		bin.pb(x);
		fore(i, 1, logK) bin.pb(mul(bin[i - 1], bin[i - 1]));
	}
	vi BM(vi& x) { // O(N^2)
		vi ls, cur;
		lli lf = -1, ld = -1;
		fore(i, 0, sz(x)) {
			lli t = 0;
			fore(j, 0, sz(cur)) t =
				(t + (lli)x[i - j - 1] * cur[j]) % mod;
			if((t - x[i]) % mod == 0) continue;
			if(!sz(cur)) {
				cur.resize(i + 1);
				lf = i;
				ld = (t - x[i]) % mod;
				continue;
			}
			lli k = (t - x[i]) * inv(ld) % mod;
			vi c(i - lf - 1);
			c.pb(k);
			fore(j, 0, sz(ls)) c.pb(-ls[j] * k % mod);
			if(sz(c) < sz(cur)) c.resize(sz(cur));
			fore(j, 0, sz(cur)) c[j] = (c[j] + cur[j]) % mod;
			if(i - lf + sz(ls) >= sz(cur))
				ls = cur, lf = i, ld = (t - x[i]) % mod;
			cur = c;
		}
		fore(i, 0, sz(cur)) cur[i] = (cur[i] % mod + mod) % mod;
		return cur;
	}
	vi mul(vi& a, vi& b) {
		vi c(2 * n + 1);
		fore(i, 0, n + 1) fore(j, 0, n + 1) c[i + j] =
			(c[i + j] + (lli)a[i] * b[j]) % mod;
		ford(i, 2 * n + 1, n + 1) {
			fore(j, 0, n) c[i - 1 - j] =
				(c[i - 1 - j] + (lli)c[i] * trans[j]) % mod;
			c[i] = 0;
		}
		c.resize(n + 1);
		return c;
	}
	lli calc(lli k) { // O(N^2logK) k is 1-indexed
		vi p(n + 1);
		p[0] = 1;
		fore(i, 0, logK) if((k >> i) & 1) p = mul(p, bin[i]);
		lli x = 0;
		fore(i, 0, n) x = (x + (lli)p[i + 1] * terms[i]) % mod;
		return x;
	}
};
