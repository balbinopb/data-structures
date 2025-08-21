#include "practice_graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Helper: Get vertex pointer by name
Vertex* getVertex(Graph G, string name) {
    Vertex* v = G.firstVertex;
    while (v != NULL) {
        if (v->name == name) return v;
        v = v->nextVertex;
    }
    return NULL;
}

// Helper: Get index of a vertex in the list
int getVertexIndex(Graph G, string name) {
    int index = 0;
    Vertex* v = G.firstVertex;
    while (v != NULL) {
        if (v->name == name) return index;
        v = v->nextVertex;
        index++;
    }
    return -1;
}

// 1. Print all paths from start to end
void printAllPathsUtil(Graph G, int u, int dest, vector<bool> &visited, vector<int> &path) {
    visited[u] = true;
    path.push_back(u);

    if (u == dest) {
        // Print path
        for (int i = 0; i < path.size(); i++) {
            // Find vertex name by index
            Vertex* v = G.firstVertex;
            for (int k = 0; k < path[i]; k++) v = v->nextVertex;
            cout << v->name;
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        // Continue DFS
        Vertex* v = G.firstVertex;
        for (int i = 0; i < u; i++) v = v->nextVertex;

        Edge* e = v->firstEdge;
        while (e != NULL) {
            if (!visited[e->destination]) {
                printAllPathsUtil(G, e->destination, dest, visited, path);
            }
            e = e->nextEdge;
        }
    }

    // Backtrack
    path.pop_back();
    visited[u] = false;
}

void printAllPaths(Graph G, string start, string end) {
    int s = getVertexIndex(G, start);
    int d = getVertexIndex(G, end);
    if (s == -1 || d == -1) return;

    int n = countVertices(G);
    vector<bool> visited(n, false);
    vector<int> path;

    printAllPathsUtil(G, s, d, visited, path);
}

// 2. BFS Traversal
void BFS(Graph G, string startName) {
    int startIndex = getVertexIndex(G, startName);
    if (startIndex == -1) return;

    int n = countVertices(G);
    vector<bool> visited(n, false);
    queue<int> q;

    visited[startIndex] = true;
    q.push(startIndex);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Print vertex name
        Vertex* v = G.firstVertex;
        for (int i = 0; i < u; i++) v = v->nextVertex;
        cout << v->name << " ";

        // Visit neighbors
        Edge* e = v->firstEdge;
        while (e != NULL) {
            if (!visited[e->destination]) {
                visited[e->destination] = true;
                q.push(e->destination);
            }
            e = e->nextEdge;
        }
    }
    cout << endl;
}

// 3. DFS Traversal
void DFSUtil(Graph G, int u, vector<bool> &visited) {
    visited[u] = true;

    Vertex* v = G.firstVertex;
    for (int i = 0; i < u; i++) v = v->nextVertex;
    cout << v->name << " ";

    Edge* e = v->firstEdge;
    while (e != NULL) {
        if (!visited[e->destination]) {
            DFSUtil(G, e->destination, visited);
        }
        e = e->nextEdge;
    }
}

void DFS(Graph G, string startName) {
    int startIndex = getVertexIndex(G, startName);
    if (startIndex == -1) return;

    int n = countVertices(G);
    vector<bool> visited(n, false);

    DFSUtil(G, startIndex, visited);
    cout << endl;
}

// 4. Detect cycle (DFS-based)
bool hasCycleUtil(Graph G, int u, vector<bool> &visited, vector<bool> &recStack) {
    visited[u] = true;
    recStack[u] = true;

    Vertex* v = G.firstVertex;
    for (int i = 0; i < u; i++) v = v->nextVertex;

    Edge* e = v->firstEdge;
    while (e != NULL) {
        if (!visited[e->destination] && hasCycleUtil(G, e->destination, visited, recStack))
            return true;
        else if (recStack[e->destination])
            return true;
        e = e->nextEdge;
    }

    recStack[u] = false;
    return false;
}

bool hasCycle(Graph G) {
    int n = countVertices(G);
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i] && hasCycleUtil(G, i, visited, recStack))
            return true;
    }
    return false;
}

// 5. Degree of a vertex (number of connections)
int degreeOfVertex(Graph G, string name) {
    int idx = getVertexIndex(G, name);
    if (idx == -1) return -1;

    // Count outgoing edges
    Vertex* v = G.firstVertex;
    for (int i = 0; i < idx; i++) v = v->nextVertex;
    int degree = 0;
    Edge* e = v->firstEdge;
    while (e != NULL) {
        degree++;
        e = e->nextEdge;
    }

    // Count incoming edges
    Vertex* temp = G.firstVertex;
    while (temp != NULL) {
        Edge* e2 = temp->firstEdge;
        while (e2 != NULL) {
            if (e2->destination == idx) degree++;
            e2 = e2->nextEdge;
        }
        temp = temp->nextVertex;
    }

    return degree;
}
