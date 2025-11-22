#include <bits/stdc++.h>
using namespace std;
const int MAX = 500000;
int n, k, visited[2][MAX+4], turn = 1;
queue<int> q;
bool flag;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	if (n == k) {
		cout << 0 << "\n";
		return 0;
	}
	visited[0][n] = 1;
	q.push(n);
	while (q.size()) {
		k += turn;
		if (k > MAX) break;
		if (visited[turn%2][k]) {
			flag = 1; break;
		}
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front(); q.pop();
			for (int nx : {x+1, x-1, x*2}) {
				if (nx < 0 || nx > MAX) continue;
				if (visited[turn%2][nx]) continue;
				visited[turn%2][nx] = visited[(turn-1)%2][x] + 1;
				if (nx == k) {
					flag = 1; break;
				}
				q.push(nx);
			}
			if (flag) break;
		}
		if (flag) break;
		turn++;
	}
	if (flag) cout << turn << "\n";
	else cout << -1 << "\n";
}