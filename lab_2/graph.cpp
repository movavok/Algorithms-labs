#include "graph.h"

Graph::Graph(int vertices) : vertexAmount(vertices) { adjacent.resize(vertexAmount + 1); }

void Graph::addEdge(int start, int end, int weight) {
    edges.push_back({start, end, weight});

    adjacent[start].push_back({end, weight});
    adjacent[end].push_back({start, weight});
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
    for (int index = 1; index <= vertexAmount; index++)
        parent[index] = index;

    int totalWeight = 0;
    int edgeCount = 0;
    cout << "Мінімальне каркасне дерево:\n";

    for (const Edge& edge : edges) {
        if (find(edge.startVertex, parent) != find(edge.endVertex, parent)) {
            unite(edge.startVertex, edge.endVertex, parent);
            totalWeight += edge.weight;
            cout << edge.startVertex << " <-(" << edge.weight << ")-> " << edge.endVertex << endl;

            edgeCount++;
            if (edgeCount == vertexAmount - 1) break;
        }
    }

    cout << "Сумарна вага: " << totalWeight << endl;
}

void Graph::dijkstra(int start, int end) {
    int size = vertexAmount + 1;

    vector<int> dist(size, INT_MAX);
    vector<bool> visited(size, false);
    vector<int> previous(size, -1);

    dist[start] = 0;

    for (int count = 0; count < vertexAmount; count++) {
        int currentVertex = -1;
        int minDistance = INT_MAX;

        for (int vertex = 1; vertex <= vertexAmount; vertex++) {
            if (!visited[vertex] && dist[vertex] < minDistance) {
                minDistance = dist[vertex];
                currentVertex = vertex;
            }
        }

        if (currentVertex == -1) break;
        visited[currentVertex] = true;

        for (const auto& [neighborVertex, weight] : adjacent[currentVertex]) {
            if (!visited[neighborVertex] && dist[currentVertex] + weight < dist[neighborVertex]) {
                dist[neighborVertex] = dist[currentVertex] + weight;
                previous[neighborVertex] = currentVertex;
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "Шляху не існує;(" << endl;
        return;
    }

    vector<int> path;
    for (int vertex = end; vertex != -1; vertex = previous[vertex]) path.push_back(vertex);
    reverse(path.begin(), path.end());

    cout << "Найкоротший шлях від " << start << " до " << end << " = " << dist[end] << endl;
    cout << "Шлях: ";
    for (int vertex : path) cout << vertex << " ";
    cout << endl;
}
