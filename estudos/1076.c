#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 49

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct {
    Node **adj;
    int *visitados;
    int vertics;
} Graph;

Graph *createGraph(int vertics) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertics = vertics;
    graph->adj = (Node **)malloc(vertics * sizeof(Node *));
    graph->visitados = (int *)malloc(vertics * sizeof(int));
    for (int i = 0; i < vertics; i++) {
        graph->adj[i] = NULL;
        graph->visitados[i] = 0;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

int DFS(Graph *graph, int vertex) {
    graph->visitados[vertex] = 1;
    int steps = 0;
    Node *adjList = graph->adj[vertex];
    Node *temp = adjList;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!graph->visitados[connectedVertex]) {
            steps += 1 + DFS(graph, connectedVertex);
        }

        temp = temp->next;
    }
    return steps;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int startVertex, V, A;
        scanf("%d", &startVertex);
        scanf("%d %d", &V, &A);

        Graph *graph = createGraph(V);

        for (int i = 0; i < A; i++) {
            int src, dest;
            scanf("%d %d", &src, &dest);
            addEdge(graph, src, dest);
        }

        int totalSteps = 2 * DFS(graph, startVertex);
        printf("%d\n", totalSteps);

        // Free the memory
        for (int i = 0; i < V; i++) {
            Node *temp = graph->adj[i];
            while (temp) {
                Node *toFree = temp;
                temp = temp->next;
                free(toFree);
            }
        }
        free(graph->adj);
        free(graph->visitados);
        free(graph);
    }

    return 0;
}
