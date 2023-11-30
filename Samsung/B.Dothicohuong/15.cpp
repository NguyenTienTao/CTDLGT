#include <bits/stdc++.h>

using namespace std;

const int maxN = 1001;

int n, m;
int indegree[maxN];
vector <int> g[maxN], topo;
queue <int> q;

int main() {
    cin >> n >> m;
    while (m--) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	indegree[v]++;
    }

    for (int u = 1; u <= n; ++u)
    	if (!indegree[u]) q.push(u);

    while (!q.empty()) {
    	int u = q.front();
    	q.pop();
    	topo.push_back(u);
    	for (auto v : g[u]) {
    		indegree[v]--;
    		if (!indegree[v]) q.push(v);
    	}
    }

    if (topo.size() < n) {
    	cout << "Khong the sap xep topo";
    } else {
        for (int i : topo) cout << i << " ";
    }

    return 0;
}
