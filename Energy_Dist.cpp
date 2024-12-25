#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight; // Compare edges by weight
}

int find(int u, vector<int> &parent) {
    if (parent[u] != u) {
        parent[u] = find(parent[u], parent); // Path compression
    }
    return parent[u];
}

bool unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    if (rootU == rootV) return false; // Already in the same set

    if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
    return true;
}

int kruskalMST(int nodes, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compareEdges); // Sort edges by weight
    vector<int> parent(nodes), rank(nodes, 0);

    // Initialize disjoint sets
    for (int i = 0; i < nodes; ++i) {
        parent[i] = i;
    }

    int mstCost = 0;
    for (const auto &edge : edges) {
        if (unionSets(edge.u, edge.v, parent, rank)) {
            mstCost += edge.weight;
            cout << "Edge included: " << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
        }
    }

    return mstCost;
}

int main() {
    int nodes = 6;
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {1, 3, 5},
        {2, 3, 8}, {2, 4, 10}, {3, 4, 6}, {3, 5, 3}, {4, 5, 7}
    };

    cout << "Minimum Spanning Tree for Energy Distribution Network:\n";
    int mstCost = kruskalMST(nodes, edges);
    cout << "Total cost of MST: " << mstCost << endl;

    return 0;
}
