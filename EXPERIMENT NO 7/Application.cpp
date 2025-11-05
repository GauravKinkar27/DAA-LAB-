// Database Indexing Systems (like B+ Trees)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to compute the cost of the Optimal Binary Search Tree
int optimalBST(vector<int>& keys, vector<int>& freq, int n) {
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            int sum = 0;
            for (int s = i; s <= j; s++) sum += freq[s];
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) + sum;
                cost[i][j] = min(cost[i][j], c);
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    cout << "📘 Database Indexing System using Optimal Binary Search Tree\n";
    cout << "------------------------------------------------------------\n";

    vector<int> keys = {10, 12, 20, 25};
    vector<int> freq = {34, 8, 50, 12};
    int n = keys.size();

    int minCost = optimalBST(keys, freq, n);

    cout << "Keys (Record IDs): ";
    for (int k : keys) cout << k << " ";
    cout << "\nAccess Frequencies: ";
    for (int f : freq) cout << f << " ";

    cout << "\n\n📊 Minimum Average Search Cost (Index Optimization): " << minCost << endl;
    cout << "✅ Database Index optimized using OBST (like B+ Tree indexing)\n";

    return 0;
}
