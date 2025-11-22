#include <bits/stdc++.h>
using namespace std;
int n, m, ret[104];
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		fill(begin(ret), end(ret), -1);
		for (int j = 0; j < m; j++) {
			if (s[j] == 'c') {
				ret[j] = 0;
			} else {
				for (int t = 0; t < j; t++) {
					if (s[t] == 'c') {
						ret[j] = j - t;
					}
				}
			}
			cout << ret[j] << " ";
		}
		cout << "\n";
	}
}