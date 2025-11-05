// Network Packet Routing using Dijkstra’s Algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u]) {
            int v = x.first, w = x.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distance from router " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "To Router " << i << ": " << dist[i] << " ms\n";
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    adj[0] = {{1, 10}, {4, 3}};
    adj[1] = {{2, 2}};
    adj[4] = {{1, 4}, {2, 8}};
    adj[2] = {{3, 9}};
    adj[3] = {{0, 7}};
    dijkstra(V, adj, 0);
    return 0;
}
