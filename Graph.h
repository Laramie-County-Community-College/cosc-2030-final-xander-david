// Graph.h
// Xander David
// This file contains the definition of the Graph class and its methods.

#pragma once
#include "LinkedList.h"
#include <utility> // for std::pair

class Graph
{
public:
    Graph(bool isDirected = false);             // Constructor
    ~Graph();                                   // Destructor
    void addVertex(int v);                      // Add a vertex
    void addEdge(int u, int v, int weight = 1); // Add an edge
    void display();                             // Display the graph
    void bfs(int start);                        // Breadth-First Search
    void dfs(int start);                        // Depth-First Search

private:
    struct VertexNode
    {
        int id;
        LinkedList<std::pair<int, int>> adjList; // Custom linked list of (vertex, weight) pairs
    };

    VertexNode **vertices; // Array of vertex nodes
    int capacity;          // Current capacity of the graph
    int size;              // Current number of vertices
    bool directed;         // Is the graph directed?

    void resize();                           // Resize the array of vertices
    int findVertexIndex(int id) const;       // Find the index of a vertex
    void freeMemory();                       // Free memory allocated for the graph
    void dfsRecursive(int v, bool *visited); // Recursive DFS helper
};
