#include "graph.h"

Graph::Graph(int vertices) : vertexAmount(vertices) {}

void Graph::addEdge(int start, int end, int weight) {
    edges.push_back({start, end, weight});
}

int Graph::find(int vertices, std::vector<int>& parent) {
    if (parent[vertices] == vertices) return vertices;
    return parent[vertices] = find(parent[vertices], parent);
}

void Graph::unite(int first, int second, std::vector<int>& parent) {
    first = find(first, parent);
    second = find(second, parent);
    if (first != second) parent[second] = first;
}

bool Graph::compareEdges(const Edge& first, const Edge& second) { return first.weight < second.weight; }

void Graph::kruskalMST() {
    sort(edges.begin(), edges.end(), Graph::compareEdges);

    vector<int> parent(vertexAmount + 1);
    for (int index = 0; index <= vertexAmount; index++)
        parent[index] = index;

    int totalWeight = 0;
    cout << "Мінімальне каркасне дерево:\n";

    for (Edge edge : edges) {
        if (find(edge.startVertex, parent) != find(edge.endVertex, parent)) {
            unite(edge.startVertex, edge.endVertex, parent);
            totalWeight += edge.weight;
            cout << edge.startVertex << " <-(" << edge.weight << ")-> " << edge.endVertex << endl;
        }
    }

    cout << "Сумарна вага: " << totalWeight << endl;
}
