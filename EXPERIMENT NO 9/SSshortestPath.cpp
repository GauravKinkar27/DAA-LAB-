#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
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

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);
    adj[0].push_back({1, 9});
    adj[0].push_back({2, 6});
    adj[0].push_back({3, 5});
    adj[0].push_back({4, 3});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 4});

    dijkstra(V, adj, 0);
    return 0;
}
