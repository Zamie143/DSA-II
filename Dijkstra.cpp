#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 100
#define INF INT_MAX
int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix
int dist[MAX_NODES];             // Distance array
bool visited[MAX_NODES];         // Visited nodes

int extractMin(int n) {
    int minDist = INF, minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int n, int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = extractMin(n);
        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex   Distance from Source " << source << "\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t\t";
        if (dist[i] == INF)
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Remove this line for directed graph
    }
   int source;
    cout << "Enter source vertex: ";
    cin >> source;
   dijkstra(n, source);
    return 0;
}
