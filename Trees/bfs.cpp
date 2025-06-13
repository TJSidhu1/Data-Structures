#include <iostream>
#include <vector>
using namespace std;

const int MAX_NODES = 100005;
vector<int> adj[MAX_NODES];  // Adjacency list for the tree
vector<bool> visited(MAX_NODES, false);

// DFS Function
void dfs(int node, int parent) {
    visited[node] = true;
    cout << "Visited Node: " << node << endl;

    for (int neighbor : adj[node]) {
        if (neighbor != parent && !visited[neighbor]) {
            dfs(neighbor, node);
        }
    }
}

int main() {
    int n; // Number of nodes
    cout << "Enter number of nodes in the tree: ";
    cin >> n;

    cout << "Enter " << n - 1 << " edges (u v) for the tree:\n";
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected tree
    }

    int startNode = 0;
    cout << "Starting DFS from node " << startNode << "...\n";
    dfs(startNode, -1);

    return 0;
}