#include<iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

// Perform iterative DFS starting from node v 
void Graph::DFS(int v) {
    // Initially mark all nodes as not visited
    vector<bool> visited(V, false);
 
    // Create a stack for DFS
    stack<int> stack;
 
    // Push the current node.
    stack.push(v);
 
    while (!stack.empty()) {

        // Pop a node from stack and print it
        v = stack.top();
        stack.pop();
 
        if (visited[v]) {
            continue;
        }

        visited[v] = true;
        cout << v << " ";
 
        // do for every edge v -> u
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i]) {
                stack.push(*i);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);

    int source_nodes[n];
    // Set all nodes as sources
    std::fill_n(source_nodes, n, 1);

    // Wait for m dependencies
    int x, y;
    for (int i = 0; i < m; i++) {
        cout << "Enter a dependency:" << endl;
        cin >> x >> y;
        g.addEdge(x, y);
        
        source_nodes[y-1] = 0; // Removes node y from the array of source nodes, simply setting as 0
    }

    // The amount of source nodes is the minimum number of interventions needed to take it all down
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (source_nodes[i] != 0) {
            count++;
        }
    }

    cout << count;

    return 0;
}
