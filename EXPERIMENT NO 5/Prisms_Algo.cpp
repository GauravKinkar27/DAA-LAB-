
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int> &weight, vector<bool> &visited, int V) {
    int minVertex = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void prims(int V, vector<vector<int>> &graph) {
    vector<int> parent(V, -1);
    vector<int> weight(V, INT_MAX);
    vector<bool> visited(V, false);
    weight[0] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = findMinVertex(weight, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < weight[v]) {
                weight[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    cout << "Edges in MST using Prim's Algorithm:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Total Minimum Cost = " << totalCost << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prims(V, graph);
    return 0;
}