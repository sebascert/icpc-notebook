#include "../../src/graph/flow/bipartite_matching.hpp"

int main() {
    Matching graph(3, 3);
    graph.add(0, 0);
    graph.add(0, 1);
    graph.add(1, 0);
    graph.add(2, 1);
    graph.add(2, 2);
    assert(graph.matching() == 3);
    Matching empty(0, 0);
    assert(empty.matching() == 0);
}
