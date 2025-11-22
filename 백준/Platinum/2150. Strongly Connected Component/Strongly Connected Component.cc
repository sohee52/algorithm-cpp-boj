#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph, graphr;
vector<bool> visited;
vector<int> order;
vector<int> component;
vector<vector<int>> ret;

void dfs_reverse(int v) { 
    visited[v] = true;
    for (int w : graphr[v]) {
        if (!visited[w]) dfs_reverse(w);
    }
    order.push_back(v);
}
void dfs(int v) {
    visited[v] = true;
    component.push_back(v);
    for (int w : graph[v]) {
        if (!visited[w]) dfs(w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    graph.assign(n + 1, {});
    graphr.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graphr[v].push_back(u);
    }

    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs_reverse(i);
    }

    visited.assign(n + 1, false);
    reverse(order.begin(), order.end());

    int scc_count = 0;
    for (int v : order) {
        if (!visited[v]) {
            component.clear();
            dfs(v);
            scc_count++;
            sort(component.begin(), component.end());
            component.push_back(-1);
            ret.push_back(component);
        }
    }
    sort(ret.begin(), ret.end());
    cout << scc_count << "\n";
    for (vector<int> v : ret) {
        for (int it : v) {
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}
