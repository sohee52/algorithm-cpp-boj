#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, visited[204], cnt;
vector<int> v[204];
queue<int> q;
void bfs(int here) {
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while(q.size()) {
        int here = q.front(); q.pop();
        for (int there : v[here]) {
            if (visited[there]) continue;
            visited[there] = 1; cnt++;
            q.push(there);
        }
    }

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    cout << cnt << "\n";
}
