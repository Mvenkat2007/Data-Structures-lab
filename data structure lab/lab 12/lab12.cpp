#include <cstdio>
#include <cstdlib>
#define MAX 100

class Graph {
private:
    int adjMatrix[MAX][MAX];
    int numVertices;

public:
    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    bool isValidVertex(int v) {
        return (v >= 0 && v < numVertices);
    }

    void insertEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1; // For undirected graph
            printf("Edge inserted between %d and %d.\n", src, dest);
        } else {
            printf("Invalid vertex index.\n");
        }
    }

    void deleteEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            if (adjMatrix[src][dest] == 1) {
                adjMatrix[src][dest] = 0;
                adjMatrix[dest][src] = 0;
                printf("Edge deleted between %d and %d.\n", src, dest);
            } else {
                printf("No edge exists between %d and %d.\n", src, dest);
            }
        } else {
            printf("Invalid vertex index.\n");
        }
    }

    void searchEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            if (adjMatrix[src][dest] == 1) {
                printf("Edge exists between %d and %d.\n", src, dest);
            } else {
                printf("No edge exists between %d and %d.\n", src, dest);
            }
        } else {
            printf("Invalid vertex index.\n");
        }
    }

    void display() {
        printf("Adjacency Matrix:\n   ");
        for (int i = 0; i < numVertices; ++i)
            printf("%3d", i);
        printf("\n");

        for (int i = 0; i < numVertices; ++i) {
            printf("%3d", i);
            for (int j = 0; j < numVertices; ++j) {
                printf("%3d", adjMatrix[i][j]);
            }
            printf("\n");
        }
    }
};

int main() {
    int vertices;
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX) {
        printf("Invalid number of vertices. Must be between 1 and %d.\n", MAX);
        return 1;
    }

    Graph g(vertices);

    int choice, src, dest;

    do {
        printf("\n--- Graph Menu ---\n");
        printf("1. Insert Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Search Edge\n");
        printf("4. Display Graph\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                g.insertEdge(src, dest);
                break;

            case 2:
                printf("Enter source and destination vertices to delete: ");
                scanf("%d %d", &src, &dest);
                g.deleteEdge(src, dest);
                break;

            case 3:
                printf("Enter source and destination vertices to search: ");
                scanf("%d %d", &src, &dest);
                g.searchEdge(src, dest);
                break;

            case 4:
                g.display();
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}
