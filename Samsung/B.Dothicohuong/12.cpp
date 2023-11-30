#include <bits/stdc++.h>

using namespace std;

bool has_edge(vector<vector<int>> graph, int u, int v) {
    for (int i : graph[u]) {
        if (i == v) {
            return true;
        }
    }
    return false;
}

void set_topo(vector<vector<int>> graph, int u, vector<bool> &visited, vector<int> &topological_sort) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            set_topo(graph, v, visited, topological_sort);
        }
    }
    topological_sort.push_back(u);
}

vector<int> topo_sort(vector<vector<int>> graph, int e) {
    vector<int> topological_sort;
    vector<bool> visited(e, false);

    for (int i = 0; i < e; i++) {
        if (!visited[i]) {
            set_topo(graph, i, visited, topological_sort);
        }
    }
    reverse(topological_sort.begin(), topological_sort.end());
    return topological_sort;
}

bool hasUniqueTopo(vector<vector<int>> graph, int e) {
    vector<int> topological_sort = topo_sort(graph, e);

    for (int i = 0; i < topological_sort.size() - 1; i++) {
        if (!has_edge(graph, topological_sort[i], topological_sort[i + 1])) {
            return false;
        }
    }

    return true;
}

int main() {
    int e;
    cin >> e;
    vector<vector<int>> graph = {{1}, {2}, {3}, {0}};

    vector<int> topo = topo_sort(graph, e);
    for (int i : topo) {
        cout << i << " ";
    }

    if (hasUniqueTopo(graph, e)) cout << "Co thu tu topo duy nhat" << endl;
    else cout << "Co nhieu thu tu topo";

  return 0;
}

