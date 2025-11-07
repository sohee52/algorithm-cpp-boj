#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, p;
map<string, string> mp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s >> p;
		mp[s] = p;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		cout << mp[s] << "\n";
	}
}
