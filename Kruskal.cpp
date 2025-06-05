#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct Edge {
    int u, v, weight;
};

int parent[MAX];

// Find operation with path compression
int findSet(int x) {
    if (parent[x] != x)
        parent[x] = findSet(parent[x]);
    return parent[x];
}

// Union operation
void unionSet(int u, int v) {
    int parentU = findSet(u);
    int parentV = findSet(v);
    parent[parentV] = parentU;
}

// Comparator for sorting edges
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    Edge edges[MAX] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Initialize parent array
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    // Sort edges by weight
    sort(edges, edges + E, compare);

    cout << "Edges in the Minimum Spanning Tree:\n";

    int count = 0; // Count edges in MST
    for (int i = 0; i < E && count < V - 1; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (findSet(u) != findSet(v)) {
            cout << u << " - " << v << " : " << w << endl;
            unionSet(u, v);
            count++;
        }
    }

    return 0;
}
