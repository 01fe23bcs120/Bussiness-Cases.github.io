#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> Edge; // Pair of (weight, node)

// Function to compute the MST using Prim's Algorithm
int primMST(int nodes, vector<vector<Edge>> &graph) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Min-heap
    vector<bool> visited(nodes, false);
    int totalCost = 0;

    // Start from node 0
    pq.push({0, 0}); // (weight, node)

    while (!pq.empty()) {
        int weight = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (visited[currentNode]) continue;
        visited[currentNode] = true;
        totalCost += weight;

        for (const auto &neighbor : graph[currentNode]) {
            if (!visited[neighbor.second]) {
                pq.push(neighbor);
            }
        }
    }

    return totalCost;
}

int main() {
    int nodes = 5; // Number of zones
    int edges = 7; // Number of connections
    vector<vector<Edge>> graph(nodes);

    // Example graph: (u, v, w) represents a connection from u to v with cost w
    vector<tuple<int, int, int>> inputEdges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    // Populate the adjacency list
    for (const auto &[u, v, w] : inputEdges) {
        graph[u].push_back({w, v});
        graph[v].push_back({w, u}); // Undirected graph
    }

    // Compute the MST and its cost
    int totalCost = primMST(nodes, graph);
    cout << "Total cost of the Minimum Spanning Tree: " << totalCost << endl;

    return 0;
}
