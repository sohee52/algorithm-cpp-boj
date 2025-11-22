#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, r[104][104], h[101], ny, nx, sz;
bool visited[104][104];
void dfs(int y, int x, int k){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		ny = y + dy[i];
		nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(r[ny][nx] >= k && !visited[ny][nx]){
			dfs(ny, nx, k);
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> r[i][j];
		}
	}
	for(int k = 1; k < 101; k++){
		fill(&visited[0][0], &visited[0][0] + 104*104, false);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(r[i][j] >= k && !visited[i][j]) {
					h[k]++; dfs(i, j, k);
				}
			}
		}
	}
	sz = sizeof(h)/sizeof(h[0]);
	auto it = max_element(h, h + sz);
	int ret = *it;
	cout << ret << "\n";
	return 0;
}