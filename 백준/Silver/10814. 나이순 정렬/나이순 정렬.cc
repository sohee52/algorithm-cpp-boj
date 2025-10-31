#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, string>> v;
bool cmp(const pair<int, string> &a, const pair<int, string> &b) {
    return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (pair<int, string> it : v) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}
