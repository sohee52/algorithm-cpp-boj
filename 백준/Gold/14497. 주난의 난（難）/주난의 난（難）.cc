#include <bits/stdc++.h>
using namespace std;
#define y1 aaa
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, m, y1, x1, y2, x2, y, x, visited[304][304], cnt;
char a[304][304];
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;
	y1--; x1--; y2--; x2--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	visited[y1][x1] = 1;
	q.push({y1, x1});
	while (true) {
		if (visited[y2][x2]) break;
		queue<pair<int, int>> temp;
		while (q.size()) {
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				if (a[ny][nx] == '0') {
					q.push({ny, nx});
				} else {
					temp.push({ny, nx});
				}
			}
		}
		q = temp;
		cnt++;
	}
	cout << cnt << "\n";
}