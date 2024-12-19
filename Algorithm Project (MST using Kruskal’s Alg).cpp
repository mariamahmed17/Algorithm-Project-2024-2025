#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure for edges
struct Edge {
    int src, dest, weight;
};

// Compare function for sorting edges by weight
bool CompareEdge(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

// Find function with path compression
int Find(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = Find(parent, parent[i]);
    return parent[i];
}

// Union function with union by rank
void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = Find(parent, x);
    int rootY = Find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Kruskal's Algorithm
vector<Edge> Kruskal(int V, vector<Edge>& edges) {
    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), CompareEdge);

    // Step 2: Initialize Union-Find structures
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> MST;       // Resulting Minimum Spanning Tree

    // Step 3: Process edges in sorted order
    for (Edge& edge : edges) {
        int u = edge.src;
        int v = edge.dest;

        // Check if adding this edge forms a cycle
        if (Find(parent, u) != Find(parent, v)) {
            MST.push_back(edge);        // Add edge to MST
            Union(parent, rank, u, v);
        }
    }
    return MST;
}

// Utility function to print the MST
void PrintMST(vector<Edge>& MST) {
    cout << "Edges in the MST:" << endl;
    for (Edge& edge : MST) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
}

int main() {
    int V = 4;       // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> MST = Kruskal(V, edges);
    PrintMST(MST);

    return 0;
}