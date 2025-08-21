#include <iostream>
#include"practice_graph.h"

int main()
{
    Graph G;
    createGraph(G);

    Vertex* v1 = createVertex("A");
    insertVertex(G, v1);

    Vertex* v2 = createVertex("B");
    insertVertex(G, v2);

    Vertex* v3 = createVertex("C");

    insertEdge(v1, 1);
    insertEdge(v1, 2);
    insertEdge(v2, 2);
    //showGraph(G);
    cout << "\nGraph structure:\n";
    Vertex* temp = G.firstVertex;
    while (temp != nullptr) {
        cout << "Vertex: " << temp->name << endl;
        temp = temp->nextVertex;
    }

    return 0;
}
