#include "practice_graph.h"

// Delete a specific edge from a vertex's adjacency list
void deleteEdge(Vertex* from, int dest) {
    if (from == NULL) return; // No vertex given

    Edge* prev = NULL;
    Edge* curr = from->firstEdge;

    while (curr != NULL) {
        if (curr->destination == dest) { // Found the edge
            if (prev == NULL) {
                from->firstEdge = curr->nextEdge; // Remove head edge
            } else {
                prev->nextEdge = curr->nextEdge;  // Skip current edge
            }
            delete curr; // Free memory
            return;
        }
        prev = curr;
        curr = curr->nextEdge;
    }
}

// Delete a vertex and all edges related to it
void deleteVertex(Graph &G, string name) {
    if (G.firstVertex == NULL) return; // Empty graph

    Vertex* prevV = NULL;
    Vertex* currV = G.firstVertex;
    int targetId = -1;
    int id = 0;

    // Find the vertex to delete
    while (currV != NULL) {
        if (currV->name == name) {
            targetId = id;
            break;
        }
        prevV = currV;
        currV = currV->nextVertex;
        id++;
    }

    if (currV == NULL) return; // Vertex not found

    // Remove edges from other vertices pointing to this vertex
    Vertex* temp = G.firstVertex;
    while (temp != NULL) {
        if (temp != currV) {
            deleteEdge(temp, targetId);
        }
        temp = temp->nextVertex;
    }

    // Delete all edges from this vertex
    Edge* e = currV->firstEdge;
    while (e != NULL) {
        Edge* del = e;
        e = e->nextEdge;
        delete del;
    }

    // Remove vertex from linked list
    if (prevV == NULL) {
        G.firstVertex = currV->nextVertex; // First vertex
    } else {
        prevV->nextVertex = currV->nextVertex;
    }
    delete currV;
}

// Count total vertices in graph
int countVertices(Graph G) {
    int count = 0;
    Vertex* v = G.firstVertex;
    while (v != NULL) {
        count++;
        v = v->nextVertex;
    }
    return count;
}

// Count total edges in graph
int countEdges(Graph G) {
    int count = 0;
    Vertex* v = G.firstVertex;
    while (v != NULL) {
        Edge* e = v->firstEdge;
        while (e != NULL) {
            count++;
            e = e->nextEdge;
        }
        v = v->nextVertex;
    }
    return count; // For directed graphs
    // return count / 2; // For undirected graphs
}

// Check if there is an edge from one vertex to another
bool isConnected(Graph G, string fromName, string toName) {
    // Find the "from" vertex
    Vertex* v = G.firstVertex;
    while (v != NULL && v->name != fromName) {
        v = v->nextVertex;
    }
    if (v == NULL) return false; // From vertex not found

    // Find the ID of "to" vertex
    int toId = -1;
    Vertex* temp = G.firstVertex;
    int id = 0;
    while (temp != NULL) {
        if (temp->name == toName) {
            toId = id;
            break;
        }
        temp = temp->nextVertex;
        id++;
    }
    if (toId == -1) return false; // To vertex not found

    // Check adjacency list for a connection
    Edge* e = v->firstEdge;
    while (e != NULL) {
        if (e->destination == toId) return true; // Connected
        e = e->nextEdge;
    }
    return false; // No connection found
}
