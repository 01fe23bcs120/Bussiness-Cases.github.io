#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return false;

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
};

int kruskalMST(int nodes, vector<Edge> &edges) {
    sort(edges.begin(), edges.end());
    DisjointSet ds(nodes);

    int mstCost = 0;
    for (const auto &edge : edges) {
        if (ds.unionSets(edge.u, edge.v)) {
            mstCost += edge.weight;
            cout << "Edge included: " << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
        }
    }
    return mstCost;
}

int main() {
    int nodes = 6; // Number of nodes in the network
    int edgesCount = 9; // Number of connections
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {1, 3, 5}, 
        {2, 3, 8}, {2, 4, 10}, {3, 4, 6}, {3, 5, 3}, {4, 5, 7}
    };

    cout << "Minimum Spanning Tree for Energy Distribution Network:\n";
    int mstCost = kruskalMST(nodes, edges);
    cout << "Total cost of MST: " << mstCost << endl;

    return 0;
}
