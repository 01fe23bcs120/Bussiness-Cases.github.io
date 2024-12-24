#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// Define the structure for the graph edge
struct Edge {
    int destination, weight;
};

// Define the structure for the priority queue element
struct Node {
    int vertex, distance;
    
    bool operator>(const Node &other) const {
        return distance > other.distance;  // Min-heap based on distance
    }
};

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<Edge>> adj;  // Adjacency list representation

    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});  // For undirected graph
    }

    // Dijkstra's algorithm to find the shortest path from source to all vertices
    vector<int> dijkstra(int source) {
        vector<int> dist(V, INT_MAX);
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        dist[source] = 0;
        pq.push({source, 0});

        while (!pq.empty()) {
            int u = pq.top().vertex;
            pq.pop();

            // Explore all neighbors of u
            for (const Edge &edge : adj[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                // Relax the edge (u, v)
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({v, dist[v]});
                }
            }
        }

        return dist;  // Return the shortest distances from source
    }
};

int main() {
    int V = 6;  // Number of locations (vertices)
    Graph g(V);

    // Adding edges (connections between locations with their distances)
    g.addEdge(0, 1, 2);  // From location 0 to 1 with distance 2
    g.addEdge(0, 2, 4);  // From location 0 to 2 with distance 4
    g.addEdge(1, 2, 1);  // From location 1 to 2 with distance 1
    g.addEdge(1, 3, 7);  // From location 1 to 3 with distance 7
    g.addEdge(2, 3, 3);  // From location 2 to 3 with distance 3
    g.addEdge(3, 4, 1);  // From location 3 to 4 with distance 1
    g.addEdge(4, 5, 2);  // From location 4 to 5 with distance 2

    // Find shortest paths from location 0
    vector<int> dist = g.dijkstra(0);

    // Output the shortest distances from source (location 0)
    cout << "Shortest distances from location 0:\n";
    for (int i = 0; i < V; i++) {
        cout << "Location " << i << ": " << dist[i] << " units\n";
    }

    return 0;
}
