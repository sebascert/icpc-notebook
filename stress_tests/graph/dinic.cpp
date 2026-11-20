#include "../../src/graph/flow/dinic.hpp"

int main() {
    Dinic flow(4);
    flow.add(0, 1, 3);
    flow.add(0, 2, 2);
    flow.add(1, 2, 1);
    flow.add(1, 3, 2);
    flow.add(2, 3, 3);
    assert(flow.flow(0, 3) == 5);
    assert(flow.flow(0, 3) == 0);
    Dinic disconnected(2);
    assert(disconnected.flow(0, 1) == 0);
}
