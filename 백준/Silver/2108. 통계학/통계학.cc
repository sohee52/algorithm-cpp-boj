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
        mp[a[i]]++;
        mx = max(a[i], mx);
        mn = min(a[i], mn);
    }

    cout << (int) round((double)sum / n) << "\n";


    sort(a, a + n);
    cout << a[n/2] << "\n";

    // 방법 1
    int many = 0;
    for (auto it : mp) {
        many = max(many, it.second);
    }
    for (auto it : mp) {
        if (it.second == many) num.push_back(it.first);
    }

    // 방법 2
    // map<int, vector<int>> freq_map; // {빈도 -> 해당 빈도를 가진 값들}
    // int many = 0;

    // for (auto it : mp) {
    //     freq_map[it.second].push_back(it.first);
    //     many = max(many, it.second);
    // }

    // num = freq_map[many]; // 최대 빈도를 가진 값들

    sort(num.begin(), num.end());
    cout << (num.size() > 1 ? num[1] : num[0]) << "\n";
    cout << mx - mn << "\n";
}
