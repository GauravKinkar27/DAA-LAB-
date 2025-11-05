// Single Source Shortest Path using Dijkstra’s Algorithm (Network Packet Routing)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Dijkstra's algorithm to find shortest path from a single source
void dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\n📶 Shortest distances from source router " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "To router " << i << " : " << dist[i] << " ms\n";
}

int main() {
    cout << "🌐 Network Packet Routing using Dijkstra’s Algorithm\n";
    cout << "---------------------------------------------------\n";

    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    adj[0] = {{1, 10}, {4, 5}};
    adj[1] = {{2, 1}, {4, 2}};
    adj[2] = {{3, 4}};
    adj[3] = {};
    adj[4] = {{1, 3}, {2, 9}, {3, 2}};

    int source = 0;
    dijkstra(V, adj, source);

    return 0;
}
