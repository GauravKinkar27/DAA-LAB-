
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Comparator function to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find)
int findParent(int v, vector<int> &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSets(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

void kruskal(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compare);  // Step 1: Sort edges

    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;
    int totalWeight = 0;

    for (auto &edge : edges) {
        int pu = findParent(edge.u, parent);
        int pv = findParent(edge.v, parent);

        if (pu != pv) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            unionSets(pu, pv, parent, rank);
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto &e : mst)
        cout << e.u << " -- " << e.v << "  weight: " << e.weight << endl;

    cout << "\nTotal Minimum Cost = " << totalWeight << endl;
}

int main() {
    int V = 5; // vertices
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}
    };

    kruskal(V, edges);
    return 0;
}