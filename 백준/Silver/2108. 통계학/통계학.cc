#include <bits/stdc++.h>
using namespace std;
int n, a[500004], mx = -4004, mn = 4004, sum;
map<int, int> mp;
vector<int> v, num;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        v.push_back(a[i]);
        if (mp.find(a[i]) != mp.end()) mp[a[i]]++;
        else mp.insert({a[i], 1});
        mx = max(a[i], mx);
        mn = min(a[i], mn);
    }

    double k = (double) sum / n;
    cout << floor(k + 0.5) << "\n";

    sort(v.begin(), v.end());
    cout << v[n/2] << "\n";

    int many = -1;
    for (auto it : mp) {
        many = max(many, it.second);
    }
    for (auto it : mp) {
        if (it.second == many) num.push_back(it.first);
    }
    sort(num.begin(), num.end());
    if (num.size() > 1) cout << num[1] << "\n";
    else cout << num[0] << "\n";

    cout << mx - mn << "\n";
}
