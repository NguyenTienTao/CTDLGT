#include <bits/stdc++.h>

using namespace std;

int n, m, X, Y;
map<int, vector<int>> graph;
vector<int> Distance(n + 1, INT_MAX);

int shortestPath() {
    Distance[X] = 0;
    queue<int> q;
    q.push(X);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == Y) break;
        for (int i : graph[x]) {
            q.push(i);
            Distance[i] = Distance[x] + 1;
        }
    }
    return Distance[Y];
}

int main() {

    cin >> n >> m >> X >> Y;

    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << shortestPath() << endl;
}
