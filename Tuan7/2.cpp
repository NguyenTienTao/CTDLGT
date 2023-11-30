#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> Graph;
bool visited[1001];
vector<vector<int>> out;

void input() {
    cin >> n >> m;
    while (m--) {
        int u, v, d;
        cin >> u >> v >> d;
        Graph.push_back({u, v, d});
    }
}

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

bool checkAll(bool a[]) {
	for (int i = 1; i <= n; i++){
		if (a[i] == false) return false;
	}
	return true;
}

int min_cost() {
    int total = 0;
    out.push_back({Graph[0][0], Graph[0][1], Graph[0][2]});
    visited[Graph[0][0]] = true;
    visited[Graph[0][1]] = true;
    total += Graph[0][2];

    while (!checkAll(visited)) {
        for (auto edge : Graph) {
            if (visited[edge[0]] && !visited[edge[1]]) {
                out.push_back({edge[0], edge[1], edge[2]});
                visited[edge[1]] = true;
                total += edge[2];
                break;
            }
            if (!visited[edge[0]] && visited[edge[1]]) {
                out.push_back({edge[0], edge[1], edge[2]});
                visited[edge[0]] = true;
                total += edge[2];
                break;
            }
        }
    }

    return total;
}

int main() {
    input();

    sort(Graph.begin(), Graph.end(), compare);

    cout << min_cost() << endl;

    for (auto edge : out) {
        cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
    }
    return 0;
}
