#include "../utilities/template.h"

#include "../../src/strings/kmp.hpp"

template<class F>
void gen(string& s, int at, int alpha, F f) {
	if (at == sz(s)) f();
	else {
		fore(i,0,alpha) {
			s[at] = (char)('a' + i);
			gen(s, at+1, alpha, f);
		}
	}
}

void test(string s) {
	vi p = kmppre(s);
	assert(p[0] == -1);
	fore(i,0,sz(s)) {
		int maxlen = -1;
		fore(len,0,i+1) {
			fore(j,0,len) {
				if (s[j] != s[i+1 - len + j]) goto fail;
			}
			maxlen = len;
fail:;
		}
		assert(maxlen == p[i + 1]);
	}
}

int main() {
	// test ~3^12 strings
	fore(n,0,13) {
		string s(n, 'x');
		gen(s, 0, 3, [&]() {
			test(s);
		});
	}
	// then ~4^10 strings
	fore(n,0,11) {
		string s(n, 'x');
		gen(s, 0, 4, [&]() {
			test(s);
		});
	}
	cout<<"Tests passed!"<<endl;
}
