#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int t, m, n, k, a, b, ret, ny, nx;
bool r[54][54], visited[54][54];
void DFS(int y, int x){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		ny = y + dy[i];
		nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if(r[ny][nx] && !visited[ny][nx]){
			DFS(ny, nx);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> m >> n >> k;
		ret = 0;
		for(int y = 0; y < n; y++){
			for(int x = 0; x < m; x++){
				r[y][x] = 0;
				visited[y][x] = 0;
			}
		}
		for(int j = 0; j < k; j++){
			cin >> a >> b;
			r[b][a] = 1;
		}
		for(int j = 0; j < n; j++){
			for(int l = 0; l < m; l++){
				if(r[j][l] && !visited[j][l]){
					ret++; DFS(j, l);
				}
			}
		}
		cout << ret << "\n";
	}
}