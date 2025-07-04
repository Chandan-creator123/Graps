// Type 1
#include <bits/stdc++.h>  // Includes all standard C++ libraries
using namespace std;
#define ll long long      // Define 'll' as shorthand for 'long long'

// -------------------------
// Adjacency list to represent graph
// adj[i] stores a list of all nodes adjacent to node i
vector<ll> adj[100];

// Visited array to track visited nodes during BFS
int visited[100] = {0};

// -------------------------
// BFS function definition
// s: starting node for BFS
// n: total number of nodes (not strictly needed here, but kept as you passed it)
void bfs(int s, int n) {
    queue<int> q;         // Queue for BFS (FIFO)
    q.push(s);            // Start BFS from node 's'
    visited[s] = 1;       // Mark the starting node as visited

    // While there are nodes to process in the queue
    while (!q.empty()) {
        int u = q.front();  // Get the front node in the queue
        q.pop();            // Remove it from the queue

        // Traverse all adjacent nodes of current node 'u'
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];     // Get the i-th neighbor of u
            if (visited[v] == 0) { // If the neighbor has not been visited yet
                visited[v] = 1;    // Mark as visited
                q.push(v);         // Add to the queue for future exploration
            }
        }
    }
}

// -------------------------
// Main function
int main() {
    int n, m;  // 'n' = number of nodes, 'm' = number of edges
    cin >> n >> m;  // Read n and m

    // Read all edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;               // Read edge between node u and node v
        adj[u].push_back(v);         // Add v to u's adjacency list
        adj[v].push_back(u);         // Add u to v's adjacency list (since graph is undirected)
    }

    // Call BFS starting from node 0
    bfs(0, n);

    // // Optional: Print visited nodes
    // cout << "Visited nodes in BFS order: ";
    // for (int i = 0; i < n; i++) {
    //     if (visited[i]) {
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;

    return 0;
}



// Type 2
#include <bits/stdc++.h> // Includes all standard C++ headers (I/O, data structures, etc.)
using namespace std;
#define ll long long      // Shortcut: 'll' means 'long long'

// ------------------------------------
// This program uses BFS (Breadth-First Search)
// to traverse a graph represented using an adjacency list.
// It starts from a given source node and visits all reachable nodes
// in level order (shortest distance from the source).
// ------------------------------------

int main() {
    ios::sync_with_stdio(false); // Fast input/output
    cin.tie(nullptr);            // Untie cin from cout for faster I/O

    int n, m;   // 'n' = number of nodes, 'm' = number of edges
    cin >> n >> m;

    // -------------------------------
    // Declare adjacency list of size 'n'
    // adj[i] will store all neighbors (connected nodes) of node i
    vector<vector<ll>> adj(n);

    // visited[i] will be 1 if node i has been visited in BFS
    // Using char saves memory (1 byte per entry)
    vector<char> visited(n, 0);
    // -------------------------------

    // Input the edges
    // For an undirected graph, add both (u -> v) and (v -> u)
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); // Edge from u to v
        adj[v].push_back(u); // Edge from v to u (since undirected)
    }

    // -------------------------------
    // Define the BFS function using a lambda expression
    // 'bfs(s)' will start BFS from node 's'
    auto bfs = [&](int s) {
        queue<int> q;         // Queue to hold nodes to process (FIFO)
        q.push(s);            // Start BFS from node s
        visited[s] = 1;       // Mark the source node as visited

        // Loop until all reachable nodes are visited
        while (!q.empty()) {
            int u = q.front(); // Get the next node from the queue
            q.pop();           // Remove it from the queue

            cout << u << ' ';  // Process the node (e.g., print it)

            // Explore all neighbors of node 'u'
            for (int v : adj[u]) {
                // If the neighbor hasn't been visited
                if (!visited[v]) {
                    visited[v] = 1; // Mark neighbor as visited
                    q.push(v);      // Add it to the queue for future processing
                }
            }
        }
    };

    // -------------------------------
    bfs(0); // Call BFS starting from node 0
    // You can change this to any starting node from 0 to n-1
}
