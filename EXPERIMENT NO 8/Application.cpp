// All-Pairs Shortest Path for City Distance Optimization using Floyd’s Algorithm

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF 99999

// Floyd–Warshall algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    cout << "\n📍 Shortest distances between every pair of cities:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    cout << "🚗 City Distance Optimization using Floyd’s Algorithm\n";
    cout << "----------------------------------------------------\n";

    int V = 4;
    vector<vector<int>> graph = {
        {0,   5,  INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph, V);
    return 0;
}
