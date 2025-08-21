#include"practice_graph.h"

 // Membuat graph kosong
void createGraph(Graph &G){
    G.firstVertex=NULL;

}

// Membuat vertex baru
Vertex* createVertex(string name){

    Vertex* newVertex=new Vertex;
    newVertex->name=name;
    newVertex->nextVertex=NULL;
    newVertex->firstEdge=NULL;
    return newVertex;

}

// Membuat edge baru
Edge* createEdge(int dest){
    Edge* newEdge=new Edge;
    newEdge->destination=dest;
    newEdge->nextEdge=NULL;
    return newEdge;

}

// Menyisipkan vertex ke dalam graph
void insertVertex(Graph &G, Vertex* v){
    if (G.firstVertex == NULL) {
        G.firstVertex = v;
    } else {//add in last
        Vertex* temp = G.firstVertex;
        while (temp->nextVertex != NULL) {
            temp = temp->nextVertex;
        }
        temp->nextVertex = v;
    }

}

// Menyisipkan edge dari vertex asal ke tujuan
void insertEdge(Vertex* from, int dest){
    if (from == NULL) return;
    Edge* newE = createEdge(dest);
    if (from->firstEdge == NULL) {
        from->firstEdge = newE;
    } else {
        Edge* temp = from->firstEdge;
        while (temp->nextEdge != NULL) {
            temp = temp->nextEdge;
        }
        temp->nextEdge = newE;
    }
}

// Menampilkan graph (adjacency list)
void showGraph(Graph G){
    Vertex* tmpVertex=G.firstVertex;
    while(tmpVertex!=NULL){
        cout<<tmpVertex->name<<endl;
        tmpVertex=tmpVertex->nextVertex;
    }

}

// Cari vertex berdasarkan nama
Vertex* searchVertex(Graph G, string name){
    Vertex* temp = G.firstVertex;
    while (temp != NULL) {
        if (temp->name == name) {
            return temp;
        }
        temp = temp->nextVertex;
    }
    return NULL;

}

