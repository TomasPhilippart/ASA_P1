#include<iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v, int dp[], int visited[]);
    int findLongestPath(int n, int source_nodes[]);
};

Graph::Graph(int V) {
    this->V = V;
    adj = vector<vector<int>>(V, vector<int>());
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

// Perform iterative DFS starting from node v 
void Graph::DFS(int v, int dp[], int visited[]) {
 
    stack<int> s;
    s.push(v);

    while (!s.empty()) {
        v = s.top();
        if (visited[v]) { // already visited
            s.pop();
            if (visited[v] == 1) { // GRAY
                visited[v] = 2; // set as BLACK

                // for every adjacent node
                for (int i = 0; i < (int) adj[v].size(); i++) {
                    dp[v] = max(dp[v], 1 + dp[adj[v][i]]);
                }
            }
        } else { // not visited
            visited[v] = 1; // set as GRAY
            for (int i = 0; i < (int) adj[v].size(); i++) {
                    if (!visited[adj[v][i]]) {
                        s.push(adj[v][i]);
                    }
                }
        }    
    }
}

// Function that returns the longest path
int Graph::findLongestPath(int n, int source_nodes[]) {

    // Dp array
    int *dp = (int *) malloc(sizeof(int) * (n));
    std::fill_n(dp, n, 1);
  
    // Visited array to know if the node has been visited previously or not
    // 0 -> WHITE
    // 1 -> GRAY
    // 2 -> BLACK
    int *visited = (int *) malloc(sizeof(int) * (n));
    std::fill_n(visited, n, 0); 
  
    // Do DFS for each source node
    for (int i = 1; i < n; i++) {
        if (source_nodes[i] != 0 && !visited[i]) { // Unvisited source node
            DFS(i, dp, visited);
        }
    }

    int longest = 0;
  
    // Traverse and find the maximum of all dp[i]
    for (int i = 1; i <= n; i++) {
        longest = max(longest, dp[i]);
    }

    
    free(dp);
    free(visited);
    return longest;
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);

    int *source_nodes = (int *) malloc(sizeof(int) * (n+1));
    // Set all nodes as sources
    std::fill_n(source_nodes+1, n+1, 1);

    // Wait for m dependencies
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g.addEdge(x, y);

        source_nodes[y] = 0; // Removes node y from the array of source nodes, simply setting as 0
    }

    // The amount of source nodes is the minimum number of interventions needed to take it all down
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (source_nodes[i] != 0) {
            count++;
        }
    }

    cout << count << " " << g.findLongestPath(n, source_nodes);
    free(source_nodes);
    return 0;
}
