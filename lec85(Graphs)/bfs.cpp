#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph {
    int n, e;
    bool isUndirected;
    map<int, vector<int>> adj;
    void bfsHelper(int node, vector<int>& visited, vector<int>& component) {
        component.push_back(node);
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            for(int i = 0; i < adj[frontNode].size(); i++) {
                int adjNode = adj[frontNode][i];
                if(!visited[adjNode]) {
                    visited[adjNode] = 1;
                    component.push_back(adjNode);
                    q.push(adjNode);
                }
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
    vector<vector<int>> bfs() {
        vector<int> visited(n, 0);
        vector<int> component;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                bfsHelper(i, visited, component);
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
    // output: 0 2 5 3 4 1
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
        directedGraph.addEdge(u, v);
    }

    // undirectedGraph.printAdjList();
    directedGraph.printAdjList();
    vector<vector<int>> ans = directedGraph.bfs();
    for (int i = 0; i < ans.size(); i++) {
        cout << "Component " << i + 1 << ":" << endl;
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}