#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> Graph[1001];
bool visited[1001] = {false};
vector<int> com_connect[1001];

bool compare(int a[], int b[]) {
    return a[2] < b[2];
}

int main() {
    int n, m; // n: number of vertices, m: number of edges
    cin >> n >> m;
    // weighted graph
    vector<vector<int>> graph;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    // sort the edges by weight
    sort(graph.begin(), graph.end(), compare);

    vector<vector<int>> mst;
    vector<bool> visited(n, false);
    visited[0] = true;
    // Prim algorithm
    int totalCost = 0;
    mst.push_back({graph[0][0], graph[0][1], graph[0][2]});
    visited[graph[0][0]] = true;
    visited[graph[0][1]] = true;
    totalCost += graph[0][2];

    while (!visitAll(visited)) {
        for (auto edge : graph) {
            if (visited[edge[0]] && !visited[edge[1]]) {
                mst.push_back({edge[0], edge[1], edge[2]});
                visited[edge[1]] = true;
                totalCost += edge[2];
                break;
            }
            if (!visited[edge[0]] && visited[edge[1]]) {
                mst.push_back({edge[0], edge[1], edge[2]});
                visited[edge[0]] = true;
                totalCost += edge[2];
                break;
            }
        }
    }

    cout << totalCost << endl;
    for (auto edge : mst) {
        cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
    }
    return 0;
}
