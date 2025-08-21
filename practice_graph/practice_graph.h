#ifndef PRACTICE_GRAPH_H_INCLUDED
#define PRACTICE_GRAPH_H_INCLUDED


#include<iostream>

using namespace std;

//typedef struct vertex* adrVertex;
//typedef struct edge* adrEdge;


// --- Edge (sisi)
struct Edge {
    int destination;      // index atau id vertex tujuan
    Edge* nextEdge;       // pointer ke edge berikutnya
};

// --- Vertex (simpul)
struct Vertex {
    string name;          // nama simpul
    Edge* firstEdge;      // pointer ke linked list edge
    Vertex* nextVertex;   // pointer ke vertex berikutnya
};

// --- Graph ---
struct Graph {
    Vertex* firstVertex;
};


//==========BASIC==============

 // Membuat graph kosong
void createGraph(Graph &G);

// Membuat vertex baru
Vertex* createVertex(string name);

// Membuat edge baru
Edge* createEdge(int dest);

// Menyisipkan vertex ke dalam graph
void insertVertex(Graph &G, Vertex* v);

// Menyisipkan edge dari vertex asal ke tujuan
void insertEdge(Vertex* from, int dest);

// Menampilkan graph (adjacency list)
void showGraph(Graph G);

// Cari vertex berdasarkan nama
Vertex* searchVertex(Graph G, string name);



//==========INTERMEDIATE ==============

// Hapus edge tertentu dari vertex
void deleteEdge(Vertex* from, int dest);

// Hapus vertex tertentu dari graph
void deleteVertex(Graph &G, string name);

// Menghitung jumlah vertex dalam graph
int countVertices(Graph G);

// Menghitung jumlah edge dalam graph
int countEdges(Graph G);

// Mengecek apakah ada edge antara dua vertex
bool isConnected(Graph G, string fromName, string toName);


//==========ADVANCED==============

// Menampilkan semua jalur dari vertex A ke vertex B
void printAllPaths(Graph G, string start, string end);

// BFS Traversal
void BFS(Graph G, string startName);

// DFS Traversal
void DFS(Graph G, string startName);

// Mengecek apakah graph memiliki siklus
bool hasCycle(Graph G);

// Menghitung degree (jumlah koneksi) dari sebuah vertex
int degreeOfVertex(Graph G, string name);



#endif // PRACTICE_GRAPH_H_INCLUDED
