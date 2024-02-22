/**
 * @file Graph_traversal_i.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list for a graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Adjacency list of vertex %d\n", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to perform Breadth-First Search (BFS) traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    // Create a boolean array to keep track of visited vertices
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    // Create a queue for BFS
    int queue[graph->numVertices];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Breadth First Traversal (starting from vertex %d):\n", startVertex);
    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex currentVertex.
        // If an adjacent vertex has not been visited, then mark it visited and enqueue it.
        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    // Print the traversal at the end of BFS
    printf("BFS Traversal: ");
    for (int i = 0; i < graph->numVertices; i++) {
        if (visited[i])
            printf("%d ", i);
    }
    printf("\n\n");

    free(visited);
}

// Recursive function to perform Depth-First Search (DFS) traversal of the graph
void DFSUtil(struct Graph* graph, int vertex, int* visited, int* stack, int* top) {
    // Mark the current node as visited
    visited[vertex] = 1;
    // Push the vertex onto the stack
    stack[++(*top)] = vertex;

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited, stack, top);
        }
        temp = temp->next;
    }
}

// Function to perform Depth-First Search (DFS) traversal of the graph
void DFS(struct Graph* graph, int startVertex) {
    // Create a boolean array to keep track of visited vertices
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    // Create a stack for DFS
    int stack[graph->numVertices];
    int top = -1;

    printf("Depth First Traversal (starting from vertex %d):\n", startVertex);
    // Call the recursive helper function to print DFS traversal starting from the startVertex
    DFSUtil(graph, startVertex, visited, stack, &top);

    // Print the content of the stack after traversal
    printf("DFS Traversal: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n\n");

    free(visited);
}

int main() {
    // Create a graph with 6 vertices
    struct Graph* graph = createGraph(6);
    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    // Print the adjacency list representation of the graph
    printf("Adjacency List Representation of the Graph:\n");
    printGraph(graph);
    printf("\n");

    // Perform BFS traversal starting from vertex 0
    BFS(graph, 0);

    // Perform DFS traversal starting from vertex 0
    DFS(graph, 0);

    return 0;
}
