#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];      // Shortest distance from src to i
    bool visited[MAX];  // True if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;  // Distance to source is 0

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the unvisited ones
        int minDist = INF, u;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] <= minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // Update dist[v] for all adjacent vertices of u
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(graph, V, source);

    return 0;
}
