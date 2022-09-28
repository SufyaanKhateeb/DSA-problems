#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph {
    int n, e;
    bool isUndirected;
    map<int, vector<int>> adj;
    void dfsHelper(int node, vector<int>& visited, vector<int>& component) {
        component.push_back(node);
        visited[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            int adjNode = adj[node][i];
            if (!visited[adjNode]) {
                dfsHelper(adjNode, visited, component);
            }
        }
    }
public:
    Graph(int n, bool isUndirected) : n(n), isUndirected(isUndirected) {}
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (isUndirected) {
            adj[v].push_back(u);
        }
    }
    void printAdjList() {
        map<int, vector<int>>::iterator it;
        for (it = adj.begin(); it != adj.end(); it++) {
            cout << it->first << " -> ";
            for (auto i : it->second) {
                cout << i << ",";
            }
            cout << endl;
        }
    }
    vector<vector<int>> dfs() {
        vector<int> visited(n, 0);
        vector<int> component;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfsHelper(i, visited, component);
                ans.push_back(component);
            }
        }
        return ans;
    }
};

int main() {
    // eg: n = 6, e = 6
    // 0 2          
    // 2 3
    // 3 4
    // 4 1
    // 1 0
    // 0 5
    // Output: 0 2 3 4 1 5
    int n, e;
    cout << "Enter the no. of nodes: ";
    cin >> n;
    cout << "Enter the no. of edges: ";
    cin >> e;

    // undirected graph
    Graph undirectedGraph(n, true);

    // directed graph
    Graph directedGraph(n, false);

    cout << "Enter the edges, follow zero based indexing: " << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        // undirectedGraph.addEdge(u, v);
        directedGraph.addEdge(u,v);
    }

    // undirectedGraph.printAdjList();
    directedGraph.printAdjList();
    vector<vector<int>> ans = directedGraph.dfs();
    for (int i = 0; i < ans.size(); i++) {
        cout << "Component " << i + 1 << ":" << endl;
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}