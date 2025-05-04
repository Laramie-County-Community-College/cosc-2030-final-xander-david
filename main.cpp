// Xander David
// COSC 2030, Laramie County Community College
// Professor: Trevor Swarm
// Date: 05/09/2025
// Purpose: This program implements a graph data structure and performs BFS and DFS traversals.
// The graph is represented using an adjacency list, and the program allows adding vertices and edges.
// It also includes a simple linked list implementation for managing adjacency lists.

// main.cpp
// This file contains the main function to demonstrate the graph functionality.

#include <iostream>
#include "Graph.h"

int main() {
    Graph g(false); // Undirected graph

    // Add vertices
    for (int i = 0; i < 8; ++i) g.addVertex(i);

    // Add edges
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 6, 7);
    g.addEdge(5, 7, 6);
    g.addEdge(6, 7, 3);

    g.display();   // Show all adjacency lists
    g.bfs(0);      // BFS from node 0
    g.dfs(0);      // DFS from node 0

    return 0;
}

