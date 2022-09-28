#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph {
    int n, e;
    bool isUndirected;
    map<int, list<int>> m;
public:
    Graph(int n, bool isUndirected): n(n),isUndirected(isUndirected) {}
    void addEdge(int u, int v) {
        m[u].push_back(v);
        if(isUndirected) {
            m[v].push_back(u);
        }
    }
    void printAdjList() {
        map<int, list<int>>::iterator it;
        for(it = m.begin(); it != m.end(); it++) {
            cout << it->first << " -> ";
            for(auto i: it->second) {
                cout << i << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, e;
    cout << "Enter the no. of nodes: ";
    cin >> n;
    cout << "Enter the no. of edges: ";
    cin >> e;

    // undirected graph
    Graph undirectedGraph(n,true);

    // directed graph
    Graph directedGraph(n,false);
    
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        undirectedGraph.addEdge(u,v);
        directedGraph.addEdge(u,v);
    }

    cout << "Undirected Graph:" << endl;
    undirectedGraph.printAdjList();
    cout << "Directed Graph: " << endl;
    directedGraph.printAdjList();

    return 0;
}