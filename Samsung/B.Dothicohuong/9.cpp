#include <bits/stdc++.h>

using namespace std;

void DFS(int u, vector<vector<int>> graph, vector<bool> &visited) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            DFS(v, graph, visited);
        }
    }
}

bool is_connected(vector<vector<int>> graph, int n) {
    vector<bool> visited(n, false);

    DFS(0, graph, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

bool euler(vector<vector<int>> graph, int n) {
    vector<int> in_degree(n, 0);
    vector<int> out_degree(n, 0);

    for (int i = 0; i < graph.size(); i++) {
        for (int v : graph[i]) {
                out_degree[i]++;
                in_degree[v]++;
            }
        }
    if (!is_connected(graph, n)) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        if (in_degree[i] != out_degree[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> graph = {{1}, {2}, {3, 8}, {4}, {2, 5}, {0, 6}, {7}, {5}, {4}};
    int n = graph.size(), max_top = 1;
    for (int i = 0; i < n; i++) {
        max_top = max(max_top, i);
        for (int v : graph[i]) {
            max_top = max(max_top, v);
        }
    }
    if (euler(graph, max_top)) cout << "Co chu trinh euler";
    else cout << "Khong co chu trinh euler";

    return 0;
}
