#include "../../src/data_structures/segtree.hpp"

int main() {
    Segtree tree(5);
    vector<lli> values(5);
    mt19937 rng(17);
    for (int it = 0; it < 10000; ++it) {
        int index = rng() % 5;
        values[index] = (int)(rng() % 100) - 50;
        tree.update(index, values[index]);
        for (int l = 0; l < 5; ++l)
            for (int r = l; r < 5; ++r)
                assert(tree.query(l, r) == accumulate(values.begin() + l, values.begin() + r + 1, 0LL));
    }
}
