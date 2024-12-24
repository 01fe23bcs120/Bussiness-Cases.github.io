#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

vector<int> dijkstra(int V, const vector<vector<pair<int, int>>> &adj, int source) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int V = 6;
    vector<vector<pair<int, int>>> adj(V);

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 7);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 3, 4, 1);
    addEdge(adj, 4, 5, 2);

    vector<int> dist = dijkstra(V, adj, 0);

    cout << "Shortest distances from location 0:\n";
    for (int i = 0; i < V; i++) {
        cout << "Location " << i << ": " << dist[i] << " units\n";
    }

    return 0;
}
