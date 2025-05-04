#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#include <algorithm>
#include <set>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<list<pair<int, int>>> adjList; // Adjacency list (pair: destination, weight)

public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    void displayGraph();
    void primMST();
    void kruskalMST();
    void dijkstra(int src);
};
// Main function
int main() {
    int vertices, choice, src, dest, weight;

    cout << "Enter number of vertices in the graph: ";
    cin >> vertices;

    Graph g(vertices);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's Algorithm\n";
        cout << "4. Kruskal's Algorithm\n";
        cout << "5. Dijkstra's Algorithm\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source vertex: ";
                cin >> src;
                cout << "Enter destination vertex: ";
                cin >> dest;
                cout << "Enter weight: ";
                cin >> weight;
                g.addEdge(src, dest, weight);
                break;

            case 2:
                g.displayGraph();
                break;

            case 3:
                g.primMST();
                break;

            case 4:
                g.kruskalMST();
                break;

            case 5:
                cout << "Enter source vertex for Dijkstra's: ";
                cin >> src;
                g.dijkstra(src);
                break;

            case 6:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
Graph::Graph(int vertices) {
    V = vertices;
    adjList.resize(V);
}

// Add edge between src and dest with given weight
void Graph::addEdge(int src, int dest, int weight) {
    adjList[src].push_back(make_pair(dest, weight));
    adjList[dest].push_back(make_pair(src, weight));  // Undirected graph
}

// Display the graph
void Graph::displayGraph() {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        for (auto& edge : adjList[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}

// Prim's Algorithm for Minimum Spanning Tree (MST)
void Graph::primMST() {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Display MST
    cout << "Prim's MST:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << " with weight " << key[i] << endl;
    }
}

// Find the root of a node for Kruskal's algorithm
int findParent(int i, vector<int>& parent) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent[i], parent);  // Path compression
}

// Union of two subsets
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        // Union by rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Kruskal's Algorithm for Minimum Spanning Tree (MST)
void Graph::kruskalMST() {
    vector<tuple<int, int, int>> edges;

    // Convert the adjacency list to an edge list
    for (int u = 0; u < V; ++u) {
        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (u < v) {
                edges.push_back(make_tuple(weight, u, v));
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    // Run Kruskal's algorithm
    cout << "Kruskal's MST:" << endl;
    for (auto& edge : edges) {
        int weight, u, v;
        tie(weight, u, v) = edge;

        if (findParent(u, parent) != findParent(v, parent)) {
            cout << "Edge: " << u << " - " << v << " with weight " << weight << endl;
            unionSets(u, v, parent, rank);
        }
    }
}

// Dijkstra's Algorithm for shortest path
void Graph::dijkstra(int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Display shortest path from src
    cout << "Dijkstra's shortest path from vertex " << src << ":" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Distance to vertex " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
    }
}