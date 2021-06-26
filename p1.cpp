#include <iostream>
#include <list>
#include <stack>
#include <vector>

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
	adj = vector<vector<int>>(V + 1, vector<int>());
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
	for (int i = 1; i < n; i++) {
		longest = max(longest, dp[i]);
	}

	free(dp);
	free(visited);
	return longest;
}

int main() {
	// Used to turn off synchronization with C I/O functions
	// See: http://gcc.gnu.org/onlinedocs/libstdc++/manual/io_and_c.html
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;	
	cin >> n >> m;
	Graph g(n);

	int *source_nodes = (int *) malloc(sizeof(int) * (n+1));
	// Set all nodes as sources
	std::fill_n(source_nodes, n+1, 1);

	// Wait for m dependencies
	int x, y, target_count = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y; 
		g.addEdge(x, y);

        if (source_nodes[y] == 1) {
            source_nodes[y] = 0; // Removes node y from the array of source nodes, simply setting as 0
            target_count++;
        }
	}
    
	cout << n - target_count << " " << g.findLongestPath(n+1, source_nodes) << endl;
	free(source_nodes);
	return 0;
}
