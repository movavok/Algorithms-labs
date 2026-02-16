#include "graph.h"

int main() {
    Graph graph(6);

    vector<Edge> edges = {
        {1, 2, 18},
        {2, 3, 17},
        {3, 5, 12},
        {3, 6, 12},
        {5, 1, 5},
        {5, 6, 15},
        {5, 4, 3},
        {4, 6, 10},
        {6, 2, 11},
        {1, 4, 7}
    };

    for (const Edge& edge : edges)
        graph.addEdge(edge.startVertex, edge.endVertex, edge.weight);

    //graph.kruskalMST();
    graph.dijkstra(1, 6);
}
