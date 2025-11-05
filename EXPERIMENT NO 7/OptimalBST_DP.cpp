#include <iostream>
#include <climits>
using namespace std;

void optimalBST(int keys[], float p[], int n) {
    float cost[n + 1][n + 1] = {0};
    float sum[n + 1][n + 1] = {0};

    for (int i = 0; i < n; i++) {
        cost[i][i] = p[i];
        sum[i][i] = p[i];
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            sum[i][j] = sum[i][j - 1] + p[j];

            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sum[i][j];
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    cout << "Minimum cost of Optimal BST: " << cost[0][n - 1] << endl;
}

int main() {
    int keys[] = {10, 12, 20};
    float prob[] = {0.34, 0.08, 0.58};
    int n = sizeof(keys) / sizeof(keys[0]);

    optimalBST(keys, prob, n);
    return 0;
}
