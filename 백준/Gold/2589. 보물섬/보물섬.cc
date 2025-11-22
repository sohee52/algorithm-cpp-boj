#include <bits/stdc++.h>
using namespace std;
int n, m, mx, visited[54][54];
char a[54][54];
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
void bfs(int y, int x) {
	while(q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx] || a[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			mx = max(mx, visited[ny][nx]);
			q.push({ny, nx});
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				memset(visited, 0, sizeof(visited));
				visited[i][j] = 1;
				q.push({i, j});
				bfs(i, j);
			}
		}
	}
	cout << mx - 1 << "\n";
}