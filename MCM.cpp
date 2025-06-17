#include <bits/stdc++.h>
using namespace std;
// Function to print optimal parenthesization
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
void matrixChainOrder(int d[], int n) {
    int M[100][100]; // Cost matrix
    int s[100][100]; // Split matrix
    for (int i = 1; i <= n; i++)
        M[i][i] = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;
           for (int k = i; k < j; k++) {
                int q = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
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

int main() {
    // Example: A1:2×3, A2:3×4, A3:4×2 → d = [2,3,4,2]
    int d[] = {2, 3, 4, 2};
    int n = sizeof(d)/sizeof(d[0]) - 1;

    matrixChainOrder(d, n);
    return 0;
}

