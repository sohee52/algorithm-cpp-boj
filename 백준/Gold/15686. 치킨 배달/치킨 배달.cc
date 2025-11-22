#include <bits/stdc++.h>
using namespace std;
int n, m, temp, cmn = 987654321;
vector<vector<int>> chickenList;
vector<pair<int, int>> home, chicken;
vector<int> v;
void combi(int start, vector<int> v) {
	if (v.size() == m) {
		chickenList.push_back(v);
		return;
	}
	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 1) home.push_back({i, j});
			else if (temp == 2) chicken.push_back({i, j});
		}
	}
	combi(-1, v);
	for (vector<int> cList : chickenList) {
		int ret = 0;
		for (pair<int, int> h : home) {
			int hmn = 987654321;
			for (int ch : cList) {
				int dist = abs(h.first-chicken[ch].first)+abs(h.second-chicken[ch].second);
				hmn = min(hmn, dist);
			}
			ret += hmn;
		}
		cmn = min(cmn, ret);
	}
	cout << cmn << "\n";
}