#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

using namespace std;

struct Edge {
    int startVertex;
    int endVertex;
    int weight;
};

class Graph {
public:
    Graph(int vertices);

    void addEdge(int start, int end, int weight);

    void kruskalMST();
    void dijkstra(int start, int end);

private:
    int vertexAmount;
    vector<Edge> edges;
    vector<vector<pair<int,int>>> adjacent;

    //helpers
    int find(int vertices, vector<int>& parent);
    void unite(int first, int second, vector<int>& parent);
    static bool compareEdges(const Edge&, const Edge&);
};

#endif // GRAPH_H
