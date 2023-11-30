#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> Graph[1001];
bool visited[1001] = {false};
vector<int> topo;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
    }
}

void DFS(int x) {
    visited[x] = true;
    for (int i : Graph[x]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    topo.push_back(x);
}

int main()
{
    input();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for (int i : topo) {
        cout << i << " ";
    }

    return 0;
}
