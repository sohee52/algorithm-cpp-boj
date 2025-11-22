#include<bits/stdc++.h>
using namespace std;
#define y1 aaaa
int n, m, k, a[101][101], visited[101][101], x1, y1, x2, y2;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<int> ret;
int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue; 
        if(!visited[ny][nx] && a[ny][nx] == 0) ret += dfs(ny, nx);
    }
    return ret;
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    cin >> m >> n >> k; 
    for(int i = 0; i < k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2; j++){
            for (int q = x1; q < x2; q++) {
            	a[j][q] = 1;
			}
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 0 && !visited[i][j]) {
                ret.push_back(dfs(i, j));
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int i : ret) {
    	cout << i << " ";
	}
    return 0; 
}
