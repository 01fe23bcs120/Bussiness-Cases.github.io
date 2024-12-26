#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Prim's Algorithm for Urban Planning and Zoning
int prim(int n, vector<vector<pair<int, int>>> &adj, vector<pair<int, int>> &zoningEdges) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    key[0] = 0; // Start from node 0
    pq.push({0, 0});
    int totalCost = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalCost += key[u];

        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Collect edges in the MST
    for (int v = 1; v < n; ++v) {
        if (parent[v] != -1) {
            zoningEdges.push_back({parent[v], v});
        }
    }

    return totalCost;
}

// Dijkstra's Algorithm for Pedestrian and Bicycle Path Planning
vector<int> dijkstra(int n, vector<vector<pair<int, int>>> &adj, int start) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 6; // Number of nodes (zones + intersections)
    vector<vector<pair<int, int>>> adj(n);

    // Add edges (u, v, weight)
    adj[0].push_back({1, 4}); adj[1].push_back({0, 4});
    adj[1].push_back({2, 2}); adj[2].push_back({1, 2});
    adj[2].push_back({3, 5}); adj[3].push_back({2, 5});
    adj[0].push_back({3, 10}); adj[3].push_back({0, 10});
    adj[3].push_back({4, 3}); adj[4].push_back({3, 3});
    adj[4].push_back({5, 1}); adj[5].push_back({4, 1});

    // Prim's Algorithm for Urban Planning
    vector<pair<int, int>> zoningEdges;
    int zoningCost = prim(n, adj, zoningEdges);
    cout << "Zoning Cost (MST): " << zoningCost << endl;
    cout << "Zoning Edges (MST): ";
    for (auto &[u, v] : zoningEdges) {
        cout << "(" << u << ", " << v << ") ";
    }
    cout << endl;

    // Dijkstra's Algorithm for Path Planning
    vector<int> distances = dijkstra(n, adj, 3); // Starting from node 3
    cout << "Shortest distances from node 3: ";
    for (int d : distances) cout << d << " ";
    cout << endl;

    return 0;
}
