//Memory Allocation using the Knapsack Problem

#include <iostream>
#include <vector>
using namespace std;

struct Program {
    string name;
    int memory;   // Memory required in MB
    int importance; // Importance 
};

// Knapsack DP function
int knapsack(vector<Program>& programs, int totalMemory, vector<int>& selected) {
    int n = programs.size();
    vector<vector<int>> dp(n + 1, vector<int>(totalMemory + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int m = 1; m <= totalMemory; m++) {
            if (programs[i - 1].memory <= m)
                dp[i][m] = max(programs[i - 1].importance + dp[i - 1][m - programs[i - 1].memory],
                               dp[i - 1][m]);
            else
                dp[i][m] = dp[i - 1][m];
        }
    }

    // Backtrack to find selected programs
    int res = dp[n][totalMemory];
    int w = totalMemory;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w])
            continue;
        else {
            selected.push_back(i - 1);
            res -= programs[i - 1].importance;
            w -= programs[i - 1].memory;
        }
    }

    return dp[n][totalMemory];
}

int main() {
    vector<Program> programs = {
        {"Antivirus", 300, 90},
        {"Video Player", 250, 70},
        {"Browser", 200, 60},
        {"IDE", 400, 100},
        {"Music Player", 150, 50}
    };

    int totalMemory;
    cout << "Enter available RAM (in MB): ";
    cin >> totalMemory;

    vector<int> selected;
    int maxImportance = knapsack(programs, totalMemory, selected);

    cout << "\n💾 Maximum system utility achieved: " << maxImportance << "\n";
    cout << "\n✅ Programs to load in memory:\n";
    for (int i : selected)
        cout << "- " << programs[i].name << " (Memory: " << programs[i].memory
             << " MB, Importance: " << programs[i].importance << ")\n";

    return 0;
}
