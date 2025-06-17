#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 100
#define INF INT_MAX

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix
int dist[MAX_NODES];             // Distance array
bool visited[MAX_NODES];         // Visited array

// -------------------- Dijkstra -----------------------
int extractMin(int n) {
    int minDist = INF, minIndex = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int n, int source) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 1; count <= n - 1; count++) {
        int u = extractMin(n);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

// ----------------- Matrix Chain Multiplication --------------------
void printOptimalParens(int s[][100], int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainOrder(int p[], int n) {
    int M[100][100]; // Cost table
    int s[100][100]; // Split points

    for (int i = 1; i <= n; i++)
        M[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            M[i][j] = INF;
            for (int k = i; k < j; k++) {
                int q = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << M[1][n] << endl;
    cout << "Optimal parenthesization: ";
    printOptimalParens(s, 1, n);
    cout << endl;
}

// -------------------- Main Program -----------------------
int main() {
    int V, E;
    cin >> V >> E;

    // Initialize graph with 0 (no edge)
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            graph[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // directed graph
    }

    int S, D;
    cin >> S >> D;

    dijkstra(V, S);

    if (dist[D] == INF)
        cout << "No path from " << S << " to " << D << endl;
    else
        cout << "Minimum cost from node " << S << " to node " << D << " is: " << dist[D] << endl;

    // Matrix Chain Multiplication
    int n; // number of matrices
    cin >> n;
    int p[105]; // dimensions array of size n+1
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    matrixChainOrder(p, n);

    return 0;
}
