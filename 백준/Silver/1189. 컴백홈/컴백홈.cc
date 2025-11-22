#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, m, k, visited[9][9];
char a[9][9];
int go(int y, int x) {
	if (y == 0 && x == m-1) {
		if (visited[y][x] == k) return 1;
		else return 0;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx] || a[ny][nx] == 'T') continue;
		visited[ny][nx] = visited[y][x] + 1;
		ret += go(ny, nx);
		visited[ny][nx] = 0;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	visited[n-1][0] = 1;
	cout << go(n-1, 0) << "\n";
}