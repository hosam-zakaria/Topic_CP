#include <bits/stdc++.h>
using namespace std;

// ----------------------
// Cycle Finder in Unicyclic Graph
// ----------------------

// N = max nodes
const int N = 2e5 + 5;
vector<int> adj[N];

// Function to find the cycle in a unicyclic graph
vector<int> findCycle(int n) {
    vector<int> deg(n + 1);       // Degree of each node
    vector<int> inCycle(n + 1, 1); // 1 if node is in cycle, 0 otherwise
    queue<int> q;

    // Initialize degrees and push leaves to queue
    for (int i = 1; i <= n; i++) {
        deg[i] = adj[i].size();
        if (deg[i] == 1) q.push(i);
    }

    // Remove leaves iteratively
    while (!q.empty()) {
        int node = q.front(); q.pop();
        inCycle[node] = 0; // Not part of cycle

        for (auto nxt : adj[node]) {
            deg[nxt]--;
            if (deg[nxt] == 1) {
                q.push(nxt);
            }
        }
    }

    // Collect nodes that are part of the cycle
    vector<int> cycleNodes;
    for (int i = 1; i <= n; i++) {
        if (inCycle[i]) cycleNodes.push_back(i);
    }
    return cycleNodes;
}

int main() {
    int n, u, v;
    cin >> n;

    // Clear adjacency list (if used in multiple testcases)
    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> cycle = findCycle(n);

    cout << "Nodes in the cycle: ";
    for (auto x : cycle) cout << x << " ";
    cout << endl;

    return 0;
}
