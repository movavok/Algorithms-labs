#include <iostream>

#include "graph.h"

int main() {
    Graph graph(6);

    graph.addEdge(1, 2, 18);
    graph.addEdge(2, 3, 17);
    graph.addEdge(3, 5, 12);
    graph.addEdge(3, 6, 12);
    graph.addEdge(5, 1, 5);
    graph.addEdge(5, 6, 15);
    graph.addEdge(5, 4, 3);
    graph.addEdge(4, 6, 10);
    graph.addEdge(6, 2, 11);
    graph.addEdge(1, 4, 7);

    graph.kruskalMST();
}
