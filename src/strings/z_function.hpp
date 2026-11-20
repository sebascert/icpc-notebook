/**
 * Lines: [7,16]
 */
#pragma once
#include "template.hpp"

vi z_function(string& s) {
	int l = 0, r = 0, n = sz(s);
	vi z(n); // z[i]=max k: s[0,k)==s[i,i+k)
	fore(i, 1, n) {
		if(i <= r) z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;
}
