#include <bits/stdc++.h>
using namespace std;
int n, temp, root, m, child, ret;
vector<int> v[54];
int go(int t) {
	int ret = 0;
	int child = 0; 
	for (int a : v[t]) {
		if (a == m) continue;
		ret += go(a);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		v[temp].push_back(i);
	}
	cin >> m;
	if (m == root) cout << 0 << "\n";
	else cout << go(root) << "\n";
}