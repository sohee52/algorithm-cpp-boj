#include <bits/stdc++.h>
using namespace std;
int n, k, visited[100004], now, cnt[100004];
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	if (n == k) {
		puts("0");
		puts("1");
		return 0;
	}
	visited[n] = 1;
	cnt[n] = 1;
	q.push(n);
	while(q.size()) {
		now = q.front(); q.pop();
		for (int next : {now+1, now-1, now*2}) {
			if (next >= 0 && next <= 100000) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = visited[now] + 1;
					cnt[next] += cnt[now];
				}
				else if (visited[next] == visited[now] + 1) {
					cnt[next] += cnt[now];
				}
			}
		}
	}
	cout << visited[k] - 1 << "\n";
	cout << cnt[k] << "\n";
}