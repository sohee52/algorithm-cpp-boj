#include <bits/stdc++.h>
using namespace std;
int n, c, a;
map<int, int> mp, mp_first;
vector<pair<int, int>> v;
bool cmp(pair<int, int> v1, pair<int, int> v2) {
	if (v1.second == v2.second) return mp_first[v1.first] < mp_first[v2.first];
	return v1.second > v2.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a; mp[a]++;
		if(mp_first[a] == 0) mp_first[a] = i + 1;
	}
	for (auto it : mp) {
		v.push_back({it.first, it.second});
	}
	sort(v.begin(), v.end(), cmp);
	for (auto it : v) {
		for (int j = 0; j < it.second; j++) {
			cout << it.first << " ";
		}
	}
}