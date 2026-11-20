#include "../utilities/template.h"
#include "../../src/strings/min_rotation.hpp"

void test(vi values) {
    vi expected = values;
    fore(i,0,sz(values)) {
        rotate(values.begin(), values.begin() + 1, values.end());
        expected = min(expected, values);
    }
    assert(getminlex(values) == expected);
}

int main() {
    test({});
    test({5});
    mt19937 rng(17);
    fore(it,0,100000) {
        vi values(rng() % 30);
        for (int& value : values) value = (int)(rng() % 5);
        test(values);
    }
    cout << "Tests passed!" << endl;
}
