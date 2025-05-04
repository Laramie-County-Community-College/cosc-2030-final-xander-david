// Graph.cpp
// Xander David
// This file contains the implementation of the Graph class and its methods.

#include "Graph.h"
#include <iostream>
#include <queue>

Graph::Graph(bool isDirected)
{
    capacity = 10;
    size = 0;
    directed = isDirected;
    vertices = new VertexNode *[capacity];
    for (int i = 0; i < capacity; ++i)
        vertices[i] = nullptr;
}

Graph::~Graph()
{
    freeMemory();
}

void Graph::addVertex(int id)
{
    if (findVertexIndex(id) != -1)
        return;

    if (size == capacity)
        resize();

    vertices[size] = new VertexNode{id};
    ++size;
}

void Graph::addEdge(int u, int v, int weight)
{
    int uIndex = findVertexIndex(u);
    int vIndex = findVertexIndex(v);

    if (uIndex == -1)
        addVertex(u), uIndex = size - 1;
    if (vIndex == -1)
        addVertex(v), vIndex = size - 1;

    vertices[uIndex]->adjList.insertFront({v, weight});

    if (!directed)
    {
        vertices[vIndex]->adjList.insertFront({u, weight});
    }
}

void Graph::display()
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Vertex " << vertices[i]->id << ": ";
        vertices[i]->adjList.print();
    }
}

int Graph::findVertexIndex(int id) const
{
    for (int i = 0; i < size; ++i)
    {
        if (vertices[i]->id == id)
            return i;
    }
    return -1;
}

void Graph::resize()
{
    capacity *= 2;
    VertexNode **newArray = new VertexNode *[capacity];
    for (int i = 0; i < capacity; ++i)
        newArray[i] = nullptr;

    for (int i = 0; i < size; ++i)
        newArray[i] = vertices[i];

    delete[] vertices;
    vertices = newArray;
}

void Graph::freeMemory()
{
    for (int i = 0; i < size; ++i)
    {
        delete vertices[i];
    }
    delete[] vertices;
}

void Graph::bfs(int start)
{
    bool *visited = new bool[size]();
    std::queue<int> q;

    int startIndex = findVertexIndex(start);
    if (startIndex == -1)
    {
        std::cout << "Start vertex not found.\n";
        delete[] visited;
        return;
    }

    q.push(start);
    visited[startIndex] = true;

    std::cout << "BFS: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        std::cout << current << " ";

        int idx = findVertexIndex(current);
        LinkedList<std::pair<int, int>> *list = &vertices[idx]->adjList;
        list->resetIterator();

        while (list->hasNext())
        {
            int neighbor = list->next().first;
            int neighborIdx = findVertexIndex(neighbor);
            if (!visited[neighborIdx])
            {
                visited[neighborIdx] = true;
                q.push(neighbor);
            }
        }
    }

    std::cout << "\n";
    delete[] visited;
}

void Graph::dfs(int start)
{
    bool *visited = new bool[size]();
    int startIndex = findVertexIndex(start);
    if (startIndex == -1)
    {
        std::cout << "Start vertex not found.\n";
        delete[] visited;
        return;
    }

    std::cout << "DFS: ";
    dfsRecursive(start, visited);
    std::cout << "\n";

    delete[] visited;
}

void Graph::dfsRecursive(int v, bool *visited)
{
    int index = findVertexIndex(v);
    if (visited[index])
        return;

    visited[index] = true;
    std::cout << v << " ";

    LinkedList<std::pair<int, int>> *list = &vertices[index]->adjList;
    list->resetIterator();

    while (list->hasNext())
    {
        int neighbor = list->next().first;
        dfsRecursive(neighbor, visited);
    }
}
