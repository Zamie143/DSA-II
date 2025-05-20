#include <bits/stdc++.h>
using namespace std;

int p[100][100]; // DP table to store max values

void knapsack(int W, int weights[], int values[], int n) {
    // Initialize DP table (base cases)
    for (int w = 0; w <= W; w++) {
        p[0][w] = 0; // No items → value = 0
    }
    for (int i = 0; i <= n; i++) {
        p[i][0] = 0; // Zero capacity → value = 0
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w) {
                // Can include the item
                p[i][w] = max(values[i-1] + p[i-1][w - weights[i-1]], p[i-1][w]);
            } else {
                // Cannot include the item
                p[i][w] = p[i-1][w];
            }
        }
    }

    // Print maximum value
    cout << "Maximum value that can be obtained: " << p[n][W] << endl;

    // Backtrack to find included items
    cout << "Items included in knapsack: " << endl;
    int i = n, k = W;
    while (i > 0 && k > 0) {
        if (p[i][k] != p[i-1][k]) {
            cout << "Item " << i << " (Weight: " << weights[i-1] << ", Value: " << values[i-1] << ")" << endl;
            k -= weights[i-1];
        }
        i--;
    }
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    int weights[100], values[100];
    cout << "Enter the weights and values of each item: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i+1 << " - Weight: ";
        cin >> weights[i];
        cout << "Item " << i+1 << " - Value: ";
        cin >> values[i];
    }

    cout << "Enter maximum weight capacity: ";
    cin >> W;

    knapsack(W, weights, values, n);
    return 0;
}
