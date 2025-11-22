#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, m, ret, visited[30];
char a[24][24];
queue<pair<int, int>> q;
void go(int y, int x, int cnt) {
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		int next = a[ny][nx] - 'A';
		if(visited[next] == 0) {
			visited[next] = 1;
			go(ny, nx, cnt+1);
			visited[next] = 0;
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
	q.push({0, 0});
	visited[a[0][0]-'A'] = 1;
	go(0, 0, 1);
	cout << ret << "\n";
}