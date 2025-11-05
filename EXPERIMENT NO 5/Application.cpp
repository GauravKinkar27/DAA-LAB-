// Minimum Cable Cost using Prim’s Algorithm

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1), key(V, INT_MAX);
    vector<bool> mstSet(V, false);
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    cout << "Cables used to connect cities:\n";
    for (int i = 1; i < V; i++)
        cout << "City " << parent[i] << " - City " << i
             << "  Cost: " << graph[i][parent[i]] << "\n";
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMST(graph, 5);
    return 0;
}

//Road Network Design using Kruskal’s Algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};
bool cmp(Edge a, Edge b) { return a.w < b.w; }

int find(vector<int>& parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent, parent[i]);
}

void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xr = find(parent, x), yr = find(parent, y);
    if (rank[xr] < rank[yr]) parent[xr] = yr;
    else if (rank[xr] > rank[yr]) parent[yr] = xr;
    else { parent[yr] = xr; rank[xr]++; }
}

void Kruskal(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;
    vector<Edge> result;
    for (auto e : edges) {
        int x = find(parent, e.u), y = find(parent, e.v);
        if (x != y) { result.push_back(e); Union(parent, rank, x, y); }
    }
    cout << "Roads selected for construction:\n";
    for (auto e : result)
        cout << e.u << " - " << e.v << "  Cost: " << e.w << endl;
}

int main() {
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6},
        {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    Kruskal(edges, 4);
    return 0;
}

