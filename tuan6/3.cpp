#include <bits/stdc++.h>

using namespace std;

int main() {
    // n: nodes, m: edges
    int m, n, source, target;
    cin >> n >> m >> source >> target;
    map<int, vector<int>> graph;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected graph
    }
    vector<int> distance(n + 1, INT_MAX);
    distance[source] = 0;
    // BFS
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        if (u == target) break;
        q.pop();
        for (int v : graph[u]) {
            q.push(v);
            distance[v] = min(distance[v], distance[u] + 1);
        }
    }

    cout << distance[target] << endl;
}
