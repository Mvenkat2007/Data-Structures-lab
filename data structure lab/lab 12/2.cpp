#include <iostream>
#include <list>
#include <unordered_map>
#include <cstdio>
#include <climits>

using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList; // Adjacency list represented by a map

public:
    void insertEdge(int src, int dest);
    void deleteEdge(int src, int dest);
    bool searchEdge(int src, int dest);
    void displayGraph();
};

// Main function
int main() {
    Graph g;
    int choice, src, dest;

    while (true) {
        printf("\nMenu:\n");
        printf("1. Insert Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Search Edge\n");
        printf("4. Display Graph\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                g.insertEdge(src, dest);
                break;

            case 2:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                g.deleteEdge(src, dest);
                break;

            case 3:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                if (g.searchEdge(src, dest)) {
                    printf("Edge exists between %d and %d\n", src, dest);
                } else {
                    printf("No edge exists between %d and %d\n", src, dest);
                }
                break;

            case 4:
                printf("Graph representation:\n");
                g.displayGraph();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// Insert an edge between src and dest
void Graph::insertEdge(int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);  // Assuming an undirected graph
    printf("Edge inserted between %d and %d\n", src, dest);
}

// Delete an edge between src and dest
void Graph::deleteEdge(int src, int dest) {
    // Remove the destination from the source's list
    adjList[src].remove(dest);
    // Remove the source from the destination's list
    adjList[dest].remove(src);
    printf("Edge deleted between %d and %d\n", src, dest);
}

// Search for an edge between src and dest
bool Graph::searchEdge(int src, int dest) {
    // Check if the destination exists in the adjacency list of the source
    for (auto it = adjList[src].begin(); it != adjList[src].end(); ++it) {
        if (*it == dest) {
            return true;
        }
    }
    return false;
}
// Display the graph
void Graph::displayGraph() {
    for (auto& node : adjList) {
        printf("%d: ", node.first);
        for (auto& adjNode : node.second) {
            printf("%d ", adjNode);
        }
        printf("\n");
    }
}