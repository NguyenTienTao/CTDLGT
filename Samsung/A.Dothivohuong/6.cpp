#include <bits/stdc++.h>

using namespace std;

void DFS(int u, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v] && v > 0) {
            DFS(v, graph, visited);
        }
    }
}

bool is_edge_connected(vector<vector<int>> &graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] > 0) {
                int tmp = graph[i][j];
                graph[i][j] = 0;
                graph[j][i] = 0;
                vector<bool> visited(n, false);
                DFS(i, graph, visited);
                for (int k = 0; k < n; k++) {
                    if (!visited[k]) {
                        return false;
                    }
                }
                graph[i][j] = tmp;
                graph[j][i] = tmp;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> graph = {{0, 1, 1, 0, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 1}, {0, 1, 1, 0, 0}, {0, 0, 1, 0, 0}};
    if (is_edge_connected(graph)) cout << "Co lien thong canh";
    else cout << "Khong co lien thong canh";
    return 0;
}
