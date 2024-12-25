#include <bits/stdc++.h>
using namespace std;

int primMST(int nodes, vector<vector<pair<int, int>>> &graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  //using min heap for finding minimum cost 
    vector<bool> visited(nodes, false);
    int totalCost = 0;

    pq.push({0, 0}); // (weight, node)

    while (!pq.empty()) {
        auto [weight, currentNode] = pq.top();
        pq.pop();

        if (visited[currentNode]) continue;
        visited[currentNode] = true;
        totalCost += weight;

        for (auto &[w, neighbor] : graph[currentNode]) {
            if (!visited[neighbor]) {
                pq.push({w, neighbor});
            }
        }
    }

    return totalCost;
}

int main() {
    int nodes = 5;
    vector<vector<pair<int, int>>> graph(nodes); //creating an adjacency list

    vector<tuple<int, int, int>> inputEdges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    for (auto &[u, v, w] : inputEdges) {
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    cout << "Total cost of the Minimum Spanning Tree: " << primMST(nodes, graph) << endl;

    return 0;
}
